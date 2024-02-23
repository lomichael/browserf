#include "BrowserEngine.h"
#include <iostream>
#include <fstream>

void BrowserEngine::loadURL(const std::string& url) {
	std::string responseContent;
	responseContent = fetchResource(url);

	DOMNode HTMLRoot;
	HTMLRoot = parseHTML(responseContent);

	// placeholders
	std::map<std::string, std::string> styles;
	styles = parseCSS("body { color: red; }");
	executeJavaScript("document.getElementById('test').textContent = 'Changed';");
	layoutPage();
	renderPage();
}

std::string BrowserEngine::fetchResource(const std::string& url) {
	// open local file and return the text
	std::ifstream file(url);
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << url << std::endl;
		return "";
	}
	return std::string((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());	
}

DOMNode BrowserEngine::parseHTML(const std::string& htmlContent) {
	// parse the text content of a single tag
	size_t endOfStartTag = htmlContent.find('>');
	size_t startOfEndTag = htmlContent.find_last_of('<');

	DOMNode node;
	node.tag = htmlContent.substr(1, endOfStartTag - 1);
	node.textContent = htmlContent.substr(endOfStartTag + 1, startOfEndTag - endOfStartTag - 1);
	return node;	
}

std::map<std::string, std::string> BrowserEngine::parseCSS(const std::string& cssContent) {
	std::map<std::string, std::string> styles;

	// parse a single CSS style
	size_t start = cssContent.find('{') + 1;
	size_t end = cssContent.find('}');
	std::string body = cssContent.substr(start, end - start);
	size_t colon = body.find(':');
	std::string property = body.substr(0, colon);
	std::string value = body.substr(colon + 1, body.find(';') - colon - 1);
	styles[property] = value;
	return styles;
}

void BrowserEngine::executeJavaScript(const std::string& jsContent) {
	std::cout << "Executing JavaScript: " << jsContent << std::endl;
}

void BrowserEngine::layoutPage() {
	std::cout << "Laying out page..." << std::endl;
}

void BrowserEngine::renderPage() {
	std::cout << "Rendering page..." << std::endl;
}

