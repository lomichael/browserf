#include "../src/BrowserEngine.h"
#include <iostream>
#include <map>
#include <string>

// TEST: parse a simple CSS rule 
// IN: body { color: red; }
// OUT: style structure associating body element with color red
void testParseCSS(BrowserEngine browser) {
	std::map<std::string, std::string> styles = browser.parseCSS("body { color: red; }");
	if (styles[" color"] == " red") {
		std::cout << "TestParseCSS: PASS" << std::endl;
	} else {
		std::cout << "TestParseCSS: FAIL" << std::endl;
		std::cout << "Expected:  red, got " << styles[" color"] << std::endl;
	}
}

// TEST: parse multiple CSS rules
// IN: body { color: red; } h1 { font-size: 14px; }
// OUT: style structures for body and h1 elements with respective styles

// TEST: parse class and ID selectors
// IN: .className { color: blue; } #idName { margin: 10px; }
// OUT: style structures for elements with specified class and ID, with respective styles

// TEST: parse descendant and child selectors
// IN: div span { color: green; } div > p { padding: 5px; }
// OUT: style structures reflecting the desendant and child relationships with styles

int main() {
	BrowserEngine browser;
	testParseCSS(browser);
	return 0;
}
