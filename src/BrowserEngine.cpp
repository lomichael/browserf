#include "BrowserEngine.h"
#include <iostream>
#include <fstream>

void BrowserEngine::loadURL(const std::string& url) {
	std::cout << "Loading URL: " << url << std::endl;

	// networking
	std::string responseContent;
	responseContent = fetchResource(url);

	// HTML parsing	
	DOMNode HTMLRoot;
	HTMLRoot = parseHTML(responseContent); 

	// CSS parsing
	std::map<std::string, std::string> styles;
	styles = parseCSS("body { color: red; }");
	executeJavaScript("document.getElementById('test').textContent = 'Changed';"); // placeholder
	layoutPage();
	renderPage();
}

std::string BrowserEngine::fetchResource(const std::string& url) {
	// TEST: fetch a local text file 
	// IN: path to local text file
	// OUT: content of text file
	std::ifstream file(url);
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << url << std::endl;
		return "";
	}
	return std::string((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
	
	// TEST: fetch content over HTTP 
	// IN: HTTP URL
	// OUT: content of response
	
	// TEST: fetch a non-existent resource 
	// IN: invalid URL
	// OUT: error message
	
	// TEST: fetch content over HTTPS 
	// IN: HTTPS URL
	// OUT: content of response
}

DOMNode BrowserEngine::parseHTML(const std::string& htmlContent) {
	// TEST: parse a minimal HTML document 
	// IN: <div>Hello World</div>
	// OUT: DOM structure with one div element containing Hello World
	size_t endOfStartTag = htmlContent.find('>');
	size_t startOfEndTag = htmlContent.find_last_of('<');

	DOMNode node;
	node.tag = htmlContent.substr(1, endOfStartTag - 1);
	node.textContent = htmlContent.substr(endOfStartTag + 1, startOfEndTag - endOfStartTag - 1);
	return node;	
	
	// TEST: parse nested HTML elements 
	// IN: <div><span>Nested</span></div>
	// OUT: DOM tree with the corresponding elements
	
	// TEST: parse elements with text content 
	// IN: <p>Some text <a href='#'>link</a></p>
	// OUT: DOM tree with text nodes and element nodes correctly placed
	
	// TEST: parse element attributes
	// IN: <img src='image.png' alt='An image'>
	// OUT: DOM node for img element with src and alt attributes parsed
}

std::map<std::string, std::string> BrowserEngine::parseCSS(const std::string& cssContent) {
	// TEST: parse a simple CSS rule 
	// IN: body { color: red; }
	// OUT: style structure associating body element with color red
	std::map<std::string, std::string> styles;
	size_t start = cssContent.find('{') + 1;
	size_t end = cssContent.find('}');
	std::string body = cssContent.substr(start, end - start);
	size_t colon = body.find(':');
	std::string property = body.substr(0, colon);
	std::string value = body.substr(colon + 1, body.find(';') - colon - 1);
	styles[property] = value;
	return styles;
	
	// TEST: parse multiple CSS rules
	// IN: body { color: red; } h1 { font-size: 14px; }
	// OUT: style structures for body and h1 elements with respective styles
	
	// TEST: parse class and ID selectors
	// IN: .className { color: blue; } #idName { margin: 10px; }
	// OUT: style structures for elements with specified class and ID, with respective styles
	
	// TEST: parse descendant and child selectors
	// IN: div span { color: green; } div > p { padding: 5px; }
	// OUT: style structures reflecting the desendant and child relationships with styles
}

void BrowserEngine::executeJavaScript(const std::string& jsContent) {
	std::cout << "Executing JavaScript: " << jsContent << std::endl;
	// TEST: execute JS that changes text content 
	// IN: document.getElementById('test').textContent = 'Changed';
	// IN: HTML structure containing <div id='test'>Original</div>
	// OUT: div's text content is 'Changed'
	
	// TEST: execute a JS function that modifies the DOM 
	// IN: a script defining and calling a function to change text content
	// OUT: DOM is modified according to the function's actions
	
	// TEST: execute JS that interacts with multiple DOM elements
	// IN: a script that uses document.querySelectorAll to modify multiple elements
	// OUT: all targeted elements are modified as expected
	 
	// TEST: attach an event listener and simulate an event
	// IN: a script that attaches a click event listener to a button that changes its text on click
	// OUT: button text changes when the event is simulated
}

void BrowserEngine::layoutPage() {
	std::cout << "Laying out page..." << std::endl;
	// TEST: calculate layout for non-nested elements
	// IN: simple HTML page with several block elements
	// OUT: a layout structure indicating a single column of elements
	
	// TEST: calculate layout with margin, border, padding
	// IN: HTML and CSS that specify margin, border, and padding for elements
	// OUT: layout structure reflects the box model dimensions
	
	// TEST: differentiate between inline and block elements in layout
	// IN: HTML with a mix of inline and block elements
	// OUT: layout structure that places inline elements differently from block elements
	
	// TEST: calculate layout for nested elements and elements with float
	// IN: HTML and CSS defining nested structures and float properties
	// OUT: layout structure reflecting nesting and float positioning
}

void BrowserEngine::renderPage() {
	std::cout << "Rendering page..." << std::endl;
	// TEST: render a page with simple text content
	// IN: a layout structure with basic text content
	// OUT: visual representation (e.g. console output, GUI window) showing text content
	
	// TEST: render text with various font sizes and styles
	// IN: layout structure specifying different font sizes and styles
	// OUT: text is rendered with the specified styles
	
	// TEST: render elements with borders and background colors
	// IN: layout structure with elements having borders and background colors
	// OUT: visual representation includes shapes and borders as specified
	
	// TEST: render elements with various color
	// IN: layout structure where elements have different text and background colors
	// OUT: colors are correctly rendered in the visual output
}

