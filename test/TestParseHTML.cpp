#include "../src/BrowserEngine.h"
#include <iostream>
#include <string>

// TEST: parse a minimal HTML document 
// IN: <div>Hello World</div>
// OUT: DOM structure with one div element containing Hello World
void testParseHTML(BrowserEngine browser) {
	DOMNode node = browser.parseHTML("<div>Hello World</div>");
	if (node.tag == "div" && node.textContent == "Hello World") {
		std::cout << "TestParseHTML: PASS" << std::endl;
	} else {
		std::cout << "TestParseHTML: FAIL" << std::endl;
	}
}
	
// TEST: parse nested HTML elements 
// IN: <div><span>Nested</span></div>
// OUT: DOM tree with the corresponding elements

// TEST: parse elements with text content 
// IN: <p>Some text <a href='#'>link</a></p>
// OUT: DOM tree with text nodes and element nodes correctly placed

// TEST: parse element attributes
// IN: <img src='image.png' alt='An image'>
// OUT: DOM node for img element with src and alt attributes parsed

int main() {
	BrowserEngine browser;
	testParseHTML(browser);
	return 0;
}
