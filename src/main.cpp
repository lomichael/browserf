#include "BrowserEngine.h"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << " requires 2 arguments" << std::endl;
		return 1;
	}

	BrowserEngine browser;
	browser.loadURL(argv[1]);
	return 0;
}
