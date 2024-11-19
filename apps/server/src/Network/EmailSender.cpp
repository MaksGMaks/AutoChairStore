#include "EmailSender.hpp"

EmailSender::EmailSender(const std::string& from_email, const std::string& username, const std::string& password, bool use_starttls)
    : m_from_email(from_email), m_username(username), m_password(password), m_use_starttls(use_starttls),
      context_(boost::asio::ssl::context::tlsv12_client), socket_(io_context_, context_) {
    context_.set_default_verify_paths();
    context_.set_verify_mode(boost::asio::ssl::verify_peer);
}

void EmailSender::sendEmail(const std::string& to_email, const std::string& subject, const std::string& body) {
    connect();
    sendCommand("EHLO " + server_);
    getResponse();
    if (m_use_starttls) {
        sendCommand("STARTTLS");
        getResponse();
        socket_.handshake(boost::asio::ssl::stream_base::client);
        sendCommand("EHLO " + server_);
        getResponse();
    }
    sendCommand("AUTH LOGIN");
    getResponse();
    sendCommand(base64_encode(m_username));
    getResponse();
    sendCommand(base64_encode(m_password));
    getResponse();
    sendCommand("MAIL FROM:<" + m_from_email + ">");
    getResponse();
    sendCommand("RCPT TO:<" + to_email + ">");
    getResponse();
    sendCommand("DATA");
    getResponse();
    sendCommand("Subject: " + subject + "\r\n\r\n" + body + "\r\n.");
    getResponse();
    sendCommand("QUIT");
    getResponse();
    disconnect();
}

void EmailSender::connect() {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    auto endpoints = resolver.resolve(server_, m_use_starttls ? port_starttls_ : port_ssl_);
    boost::asio::connect(socket_.lowest_layer(), endpoints);
    if (!m_use_starttls) {
        socket_.handshake(boost::asio::ssl::stream_base::client);
    }
}

void EmailSender::sendCommand(const std::string& command) {
    boost::asio::write(socket_, boost::asio::buffer(command + "\r\n"));
}

std::string EmailSender::getResponse() {
    boost::asio::streambuf response;
    boost::asio::read_until(socket_, response, "\r\n");
    std::istream response_stream(&response);
    std::string response_line;
    std::getline(response_stream, response_line);
    std::cout << "Response: " << response_line << std::endl;
    return response_line;
}

void EmailSender::disconnect() {
    socket_.lowest_layer().close();
}

std::string EmailSender::base64_encode(const std::string& s) {
    using namespace boost::archive::iterators;
    typedef base64_from_binary<transform_width<const char *, 6, 8>> base64_text;

    std::stringstream os;
    std::copy(base64_text(s.c_str()), base64_text(s.c_str() + s.size()), std::ostream_iterator<char>(os));
    os << std::string((3 - s.size() % 3) % 3, '=');
    return os.str();
}
