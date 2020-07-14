#include "parser.h"
#include <iostream>

void Parser::parseFile(const std::string &fileName) {
    Lexer lexer(fileName);
    for (int i = 0; i < lexer.contents.size(); i++) {
        Token token = lexer.next();
        if (!token.value.empty()) {
            tokenList.push_back(token);
            std::cout << token.value << std::endl;
        }
        if (token.endingToken != nullptr) {
            std::cout << token.endingToken->value << std::endl;
        }
    }
    std::cout << "Number of lines: " << lexer.lineNumber << std::endl;
}