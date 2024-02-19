#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <sstream>

class Url {
public:
	Url(std::string url);
	std::string request();
private:
	std::string scheme;
	std::string host;
	std::string path;
};

Url::Url(std::string url) {
	// processing the scheme of the URL
	delimiter = "://";
	scheme = url.substr(0, url.find(delimiter));
	url.erase(0, url.find(delimiter) + delimiter.length());	
	assert(scheme == "http");

	// processing the hostname of the URL
	if url.find("/") == std::string::npos {
		url.append("/");	
	}

	host = url.substr(0, url.find("/"));
	url.erase(0, url.find("/") + 1);
	
	path = "/";
	path.append(url);
}

std::string URL::request() {
	//
	boost::asio::io_context io_ctx;
	// 
	boost::asio::ip::tcp::socket sock(io_ctx);
	// resolving the host name and port
	boost::asio::ip::tcp::resolver resolver(ios);
	auto endpoints = resolver.resolve(host, 80);	

	// connecting the socket to the server endpoints
	boost::asio::connect(sock, endpoints);

	// creating and sending an HTTPS request
	std::stringstream request;
	request << "GET " << path << " HTTP/1.0\r\n"
		<< "Host: " << host << "\r\n"
		<< "Accept: */*\r\n"
		<< "Connection: close\r\n\r\n";
	boost::asio::write(sock, boost::asio::buffer(request.str()));

	// reading the response
	boost::asio::streambuf response;
	boost::asio::read_until(sock, response, "\r\n");

	// checking the response status 
	std::istream response_stream(&response);
	std::string http_version;
	response_stream >> http_version;
	unsigned int status_code;
	response_stream >> status_code;
	std::string status_message;
	std::getline(response_stream, status_message);
	if (!response_stream || http_version.substr(0, 5) != "HTTP/")
		return "Invalid response\n";

	// read the headers
	boost::asio::read_until(sock, response, "\r\n\r\n");
	// process the headers
	// ...
	
	// write to output
	std::string response_body;
	if (response.size() > 0)
		response_body = std::string(std::istreambuf_iterator<char>(&response), {});

	// read until the end of stream
	boost::system::error_code error;
	while (boost::asio::read(sock, response, boost::asio::transfer_at_least(1), error))
		response_body.append(std::istreambuf_iterator<char>(&response), {});
	if (error != boost::asio::error::eof)
		throw boost::system::system_error(error);

	return response_body;
}
