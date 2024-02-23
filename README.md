# browserf 
[![MIT License](https://img.shields.io/badge/license-MIT-blue)](/LICENSE)
[![justforfunnoreally.dev badge](https://img.shields.io/badge/justforfunnoreally-dev-9ff)](https://justforfunnoreally.dev)

A web browser written in C++.

> **DISCLAIMER**: This is a hobby project and a work-in-progress.

## Build
browserf has been tested on Debian Linux.

Prerequisites:
- git
- gcc 
- GNU make

To clone the repository and build the browser:
```sh
git clone https://codeberg.org/lomichael/browserf
cd browserf
make
```

## Usage
**Fetch and display from a given URL**:
```sh
./browserf <path/to/file>
```

## Tests
**Build tests**:
```sh
make test
```

**Run tests**:
```sh
./test/<TestFunction>
```
- Networking
    - [X] Fetch a local text file.
    - [ ] Fetch content over HTTP.
    - [ ] Fetch a non-existent resource.
    - [ ] Fetch content over HTTPS.
- HTML Parser
    - [X] Parse a minimal HTML document.
    - [ ] Parse nested HTML elements.
    - [ ] Parse elements with text content.
    - [ ] Parse element attributes.
- CSS Parser
    - [X] Parse a simple CSS rule.
    - [ ] Parse multiple CSS rules.
    - [ ] Parse class and ID selectors.
    - [ ] Parse descendant and child selectors.
- JavaScript Engine
    - [ ] Execute JavaScript that changes text content.
    - [ ] Execute a JavaScript function that modifies the DOM.
    - [ ] Execute JavaScript that interacts with multiple DOM elements.
    - [ ] Attach an event listener and simulate an event. 
- Page Layout
    - [ ] Calculate layout for non-nested elements.
    - [ ] Calculate layout with margin, border, padding.
    - [ ] Differentiate between inline and block elements in layout.
    - [ ] Calculate layout for nested elements and elements with float. 
- Page Renderer
    - [ ] Render a page with simple text content.
    - [ ] Render text with various font sizes and styles.
    - [ ] Render elements with borders and background colors.
    - [ ] Render elements with various colors. 

## Resources
- [Web Browser Engineering](browser.engineering)
- [Let's build a browser engine!](https://limpet.net/mbrubeck/2014/08/08/toy-layout-engine-1.html)

## License
browserf is licensed under the MIT License. See `LICENSE` in the project for details.
