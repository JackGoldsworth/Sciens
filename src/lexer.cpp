#include <iostream>
#include "lexer.h"
#include "token.h"

Lexer::Lexer(const std::string &fileName) {
    contents = readFile(fileName);
    lineNumber = 1;
}

void Lexer::analyzeFile() {
    for (auto character : contents) {
        if (character == '\n') {
            lineNumber++;
            isToken();
            continue;
        } else if (character == ' ') {
            isToken();
            continue;
        } else if (character == ';') {
            isToken();
            continue;
        } else if (character == '{') {
            isToken();
            continue;
        } else if (character == '}') {
            if(!tokenBuffer.empty() && tokenBuffer[0] == '{') {
                isToken();
                continue;
            }
            syntaxError('}');
        }
        tokenBuffer.push_back(character);
    }
    std::cout << "Number of lines: " << lineNumber << std::endl;
}

bool Lexer::isToken() {
    if (!tokenBuffer.empty()) {
        std::cout << "TOKEN FOUND: " << std::string(tokenBuffer.begin(), tokenBuffer.end()) << std::endl;
        tokenBuffer.clear();
        return true;
    }
    return false;
}

void Lexer::syntaxError(char character) {
    std::cout << "There was an unexpected character: " << character << " on line " << lineNumber << std::endl;
}

std::vector<char> Lexer::readFile(const std::string &fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return std::vector<char>(content.begin(), content.end());
}