#include <iostream>
#include "lexer.h"

Lexer::Lexer(const std::string &fileName) {
    contents = readFile(fileName);
    currentChar = 0;
    lineNumber = 1;
}

TokenType Lexer::next() {
    char character = contents[currentChar++];
    switch (character) {
        case '\n':
            lineNumber++;
            isToken();
            break;
        case ' ':
            isToken();
            break;
        case ';':
            isToken();
            return SEMI_COLON;
        default:
            tokenBuffer.push_back(character);
    }
    return NOT_FOUND;
}

bool Lexer::isToken() {
    if (!tokenBuffer.empty()) {
        std::cout << "TOKEN FOUND: " << std::string(tokenBuffer.begin(), tokenBuffer.end()) << std::endl;
        tokenBuffer.clear();
        return true;
    }
    return false;
}

std::vector<char> Lexer::readFile(const std::string &fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return std::vector<char>(content.begin(), content.end());
}