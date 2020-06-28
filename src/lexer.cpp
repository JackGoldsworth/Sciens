#include <iostream>
#include "lexer.h"
#include "token.h"

Lexer::Lexer(const std::string &fileName) {
    contents = readFile(fileName);
    lineNumber = 0;
}

void Lexer::analyzeFile() {
    for (auto character : contents) {
        if (character == '\n') {
            lineNumber++;
            if (!tokenBuffer.empty()) {
                std::cout << "TOKEN FOUND: " << std::string(tokenBuffer.begin(), tokenBuffer.end()) << std::endl;
                tokenBuffer.clear();
            }
            continue;
        } else if (character == ' ') {
            if (!tokenBuffer.empty()) {
                std::cout << "TOKEN FOUND: " << std::string(tokenBuffer.begin(), tokenBuffer.end()) << std::endl;
                tokenBuffer.clear();
            }
            continue;
        }
        //std::cout << character << std::endl;
        tokenBuffer.push_back(character);
    }
}

std::vector<char> Lexer::readFile(const std::string &fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return std::vector<char>(content.begin(), content.end());
}