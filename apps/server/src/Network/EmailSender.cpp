#include "EmailSender.hpp"

EmailSender::EmailSender(const std::string& server, const std::string& port, const std::string& from_email, const std::string& username, const std::string& password)
: m_server(server), m_port(port), m_from_email(from_email)
, m_username(username), m_password(password)
, context_(boost::asio::ssl::context::sslv23)
, socket_(io_context_, context_) {
    context_.set_verify_mode(boost::asio::ssl::verify_peer);
    context_.set_default_verify_paths();
}

void EmailSender::sendEmail(const std::string& to_email, const std::string& subject, const std::string& body) {
    connect();
    sendCommand("EHLO " + m_server, {250});
    sendCommand("AUTH LOGIN", {334});
    sendCommand(base64_encode(m_username), {334});
    sendCommand(base64_encode(m_password), {235});
    sendCommand("MAIL FROM:<" + m_from_email + ">", {250});
    sendCommand("RCPT TO:<" + to_email + ">", {250});
    sendCommand("DATA", {354});
    sendCommand("Subject: " + subject + "\r\n\r\n" + body + "\r\n.", {250});
    sendCommand("QUIT", {221});
    disconnect();
}

void EmailSender::connect() {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    auto endpoints = resolver.resolve(m_server, m_port);
    boost::asio::connect(socket_.lowest_layer(), endpoints);
    socket_.handshake(boost::asio::ssl::stream_base::client);
    
    // Read the initial greeting from the server
    boost::asio::streambuf response;
    boost::asio::read_until(socket_, response, "\r\n");
    std::istream response_stream(&response);
    std::string response_line;
    std::getline(response_stream, response_line);
    std::cout << "Initial Response: " << response_line << std::endl;
    if (response_line.substr(0, 3) != "220") {
        throw std::runtime_error("Unexpected SMTP response: " + response_line);
    }
}

void EmailSender::sendCommand(const std::string& command, const std::vector<int>& expected_responses) {
    boost::asio::write(socket_, boost::asio::buffer(command + "\r\n"));
    boost::asio::streambuf response;
    boost::asio::read_until(socket_, response, "\r\n");
    std::istream response_stream(&response);
    std::string response_line;
    std::getline(response_stream, response_line);
    std::cout << "Response: " << response_line << std::endl;
    int response_code = std::stoi(response_line.substr(0, 3));
    if (std::find(expected_responses.begin(), expected_responses.end(), response_code) == expected_responses.end()) {
        throw std::runtime_error("Unexpected SMTP response: " + response_line);
    }
}

void EmailSender::disconnect() {
    socket_.lowest_layer().close();
}

std::string EmailSender::base64_encode(const std::string& s) {
    static const char lookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string encoded;
    int val = 0, valb = -6;
    for (unsigned char c : s) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(lookup[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) encoded.push_back(lookup[((val << 8) >> (valb + 8)) & 0x3F]);
    while (encoded.size() % 4) encoded.push_back('=');
    return encoded;
}
