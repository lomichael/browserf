#include "../src/BrowserEngine.h"
#include <fstream>
#include <iostream>
#include <string>

// TEST: fetch a local text file 
// IN: path to local text file
// OUT: content of text file
void testFetchResource(std::string path, BrowserEngine browser) {
	std::string expected = "<html></html>\n";
	std::string result = browser.fetchResource(path);
	if (result == expected) {
		std::cout << "TestFetchResource: PASS" << std::endl;
	} else {
		std::cout << "TestFetchResource: FAIL" << std::endl;
		std::cout << "Result: " << result << std::endl;
		std::cout << "Expected: " << expected << std::endl;
	}
}

// TEST: fetch content over HTTP 
// IN: HTTP URL
// OUT: content of response

// TEST: fetch a non-existent resource 
// IN: invalid URL
// OUT: error message

// TEST: fetch content over HTTPS 
// IN: HTTPS URL
// OUT: content of response

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << " expects 2 arguments" << std::endl;
		return 1;
	}

	BrowserEngine browser;
	testFetchResource(argv[1], browser);
	return 0;
}
