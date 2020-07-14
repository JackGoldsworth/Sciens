#include <iostream>
#include "lexer.h"

Lexer::Lexer(const std::string &fileName) {
    insertTokens();
    contents = readFile(fileName);
    currentChar = 0;
    lineNumber = 1;
}

std::pair<TokenType, TokenType> Lexer::next() {
    char character = contents[currentChar++];
    switch (character) {
        case '\n':
            lineNumber++;
            isToken(NOT_FOUND);
            break;
        case ' ':
            isToken(NOT_FOUND);
            break;
        case ';':
            return isToken(SEMI_COLON);
        case '[':
            return isToken(LEFT_SQUARE_BRACKET);
        case ']':
            return isToken(RIGHT_SQUARE_BRACKET);
        case '(':
            return isToken(LEFT_CURLY_BRACKET);
        case ')':
            return isToken(RIGHT_CURLY_BRACKET);
        case ':':
            return isToken(COLON);
        default:
            tokenBuffer.push_back(character);
    }
    return std::pair<TokenType, TokenType>(NOT_FOUND, NOT_FOUND);
}

std::pair<TokenType, TokenType> Lexer::isToken(TokenType type) {
    if (!tokenBuffer.empty()) {
        std::string tokenChars = std::string(tokenBuffer.begin(), tokenBuffer.end());
        std::cout << "TOKEN FOUND: " << tokenChars << std::endl;
        tokenBuffer.clear();
        try {
            TokenType firstToken = tokens.at(tokenChars);
            return std::pair<TokenType, TokenType>(firstToken, type);
        } catch (const std::out_of_range& oor) {
            return std::pair<TokenType, TokenType>(IDENTIFIER, type);
        }
    }
    return std::pair<TokenType, TokenType>();
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