#include "parser.h"
#include "lexer.h"
#include <iostream>

void Parser::parseFile(const std::string &fileName) {
    Lexer lexer(fileName);
    for (int i = 0; i < lexer.contents.size(); i++) {
        lexer.next();
        //std::cout << "TOKEN: " << token << std::endl;
        char endingToken = lexer.endTokenBuffer;
        std::string identifier = lexer.identifierBuffer;
        if (!identifier.empty()) {
            std::cout << "TOKEN: " << identifier << std::endl;
        }
        if (endingToken != NULL) {
            std::cout << "TOKEN: " << endingToken << std::endl;
        }
    }
    std::cout << "Number of lines: " << lexer.lineNumber << std::endl;
}