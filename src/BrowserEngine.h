#ifndef BROWSERENGINE_H
#define BROWSERENGINE_H

#include <string>

class BrowserEngine {
public:
	void loadURL(const std::string& url);
private:
	void fetchResource(const std::string& url);
	void parseHTML(const std::string& htmlContent);
	void parseCSS(const std::string& cssContent);
	void executeJavaScript(const std::string& jsContent);
	void renderPage();
	void layoutPage();
};

#endif
