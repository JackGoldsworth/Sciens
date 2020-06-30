#include "parser.h"
#include "lexer.h"
#include <iostream>

void Parser::parseFile(const std::string &fileName) {
    Lexer lexer(fileName);
    for (int i = 0; i < lexer.contents.size(); i++) {
        TokenType token = lexer.next();
        if(token != NOT_FOUND) {
            std::cout << "TOKEN: " << token << std::endl;
        }
    }
    std::cout << "Number of lines: " << lexer.lineNumber << std::endl;
}