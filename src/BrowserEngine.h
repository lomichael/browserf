#ifndef BROWSERENGINE_H
#define BROWSERENGINE_H

#include <map>
#include <string>

struct DOMNode {
	std::string tag;
	std::string textContent;
};

struct Style {
	std::string selector;
	std::string property;
	std::string value;
};

class BrowserEngine {
public:
	void loadURL(const std::string& url);
private:
	std::string fetchResource(const std::string& url);
	DOMNode parseHTML(const std::string& htmlContent);
	std::map<std::string, std::string> parseCSS(const std::string& cssContent);
	void executeJavaScript(const std::string& jsContent);
	void renderPage();
	void layoutPage();
};

#endif
