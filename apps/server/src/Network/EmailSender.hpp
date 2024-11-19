#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <sstream>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>

class EmailSender {
public:
    EmailSender(const std::string& from_email, const std::string& username, const std::string& password, bool use_starttls = false);
    ~EmailSender() = default;

    void sendEmail(const std::string& to_email, const std::string& subject, const std::string& body);

private:
    void connect();
    void sendCommand(const std::string& command);
    std::string getResponse();
    void disconnect();
    std::string base64_encode(const std::string& s);

    std::string m_from_email;
    std::string m_username;
    std::string m_password;
    bool m_use_starttls;
    boost::asio::io_context io_context_;
    boost::asio::ssl::context context_;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
    const std::string server_ = "smtp.gmail.com";
    const std::string port_starttls_ = "587";
    const std::string port_ssl_ = "465";
};
