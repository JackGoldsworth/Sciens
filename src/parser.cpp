#include "parser.h"
#include "lexer.h"
#include <iostream>

void Parser::parseFile(const std::string &fileName) {
    Lexer lexer(fileName);
    for (int i = 0; i < lexer.contents.size(); i++) {
        std::pair<TokenType, TokenType> token = lexer.next();
        if(token.first != NOT_FOUND) {
           std::cout << "TOKEN: " << token.first + token.second << std::endl;
        }
    }
    std::cout << "Number of lines: " << lexer.lineNumber << std::endl;
}