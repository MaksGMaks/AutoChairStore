#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class EmailSender {
public:
    EmailSender(const std::string& server, const std::string& port, const std::string& from_email, const std::string& username, const std::string& password);
    ~EmailSender() = default;

    void sendEmail(const std::string& to_email, const std::string& subject, const std::string& body);
    
private:
    void connect();
    void sendCommand(const std::string& command, const std::vector<int>& expected_responses = {250});
    void disconnect();
    std::string base64_encode(const std::string& s);

    std::string m_server;
    std::string m_port;
    std::string m_from_email;
    std::string m_username;
    std::string m_password;
    boost::asio::io_context io_context_;
    boost::asio::ssl::context context_;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
};
