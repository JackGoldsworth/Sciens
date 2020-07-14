#include <iostream>
#include "lexer.h"

Lexer::Lexer(const std::string &fileName) {
    insertTokens();
    contents = readFile(fileName);
    currentChar = 0;
    lineNumber = 1;
}

TokenType Lexer::next() {
    char character = contents[currentChar++];
    if (endTokenBuffer != NULL) {
        endTokenBuffer = NULL;
    }
    if (!identifierBuffer.empty()) {
        identifierBuffer = "";
    }
    switch (character) {
        case '\n':
            lineNumber++;
            return isToken();
        case ' ':
            return isToken();
        case ';':
            endTokenBuffer = ';';
            return isToken();
        case '[':
            endTokenBuffer = '[';
            return isToken();
        case ']':
            endTokenBuffer = ']';
            return isToken();
        case '(':
            endTokenBuffer = '(';
            return isToken();
        case ')':
            endTokenBuffer = ')';
            return isToken();
        case ':':
            endTokenBuffer = ':';
            return isToken();
        case ',':
            endTokenBuffer = ',';
            return isToken();
        default:
            tokenBuffer.push_back(character);
    }
    return NOT_FOUND;
}

TokenType Lexer::isToken() {
    if (!tokenBuffer.empty()) {
        std::string tokenChars = std::string(tokenBuffer.begin(), tokenBuffer.end());
        try {
            TokenType firstToken = tokens.at(tokenChars);
            tokenBuffer.clear();
            return firstToken;
        } catch (const std::out_of_range &oor) {
            identifierBuffer = tokenChars;
            tokenBuffer.clear();
            return IDENTIFIER;
        }
    }
    return NOT_FOUND;
}

void Lexer::insertTokens() {
    tokens["if"] = IF;
    tokens["else"] = ELSE;
}

std::vector<char> Lexer::readFile(const std::string &fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return std::vector<char>(content.begin(), content.end());
}