#include "parser.h"
#include <iostream>

void Parser::parseFile(const std::string &fileName) {
    lexer = new Lexer(fileName);
    for (int i = 0; i < lexer->contents.size(); i++) {
        Token token = lexer->next();
        if (!token.value.empty()) {
            tokenList.push_back(token);
            std::cout << token.value << std::endl;
        }
        if (token.endingToken != nullptr) {
            tokenList.push_back(*token.endingToken);
            std::cout << token.endingToken->value << std::endl;
        }
    }
    std::cout << "Number of lines: " << lexer->lineNumber << std::endl;
    validateTokens();
}

bool Parser::validateTokens() {
    TokenType expectedType = EOF_TOKEN;
    for (auto const &token : tokenList) {
        if (expectedType != EOF_TOKEN && token.type != expectedType) {
            std::cout << "There was an unexpected token found: " << token.value << ", when the expected type is "
                      << expectedType << ". Found on line: " << token.lineNumber << std::endl;
            return false;
        }
        if (token.type == WRAP) {
            expectedType = IDENTIFIER;
        }
    }
    return true;
}