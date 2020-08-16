#include <iostream>
#include "lexer.h"

Lexer::Lexer(const std::string &fileName) {
    insertTokens();
    contents = readFile(fileName);
    currentChar = 0;
    lineNumber = 1;
}

Token Lexer::next() {
    char character = contents[currentChar++];
    Token tempToken;
    switch (character) {
        case '\n':
            lineNumber++;
            return isToken(tempToken, "\n");
        case ' ':
            return isToken(tempToken, " ");
        case ';':
            return isToken(tempToken, ";");
        case '[':
            return isToken(tempToken, "[");
        case ']':
            return isToken(tempToken, "]");
        case '(':
            return isToken(tempToken, "(");
        case ')':
            return isToken(tempToken, ")");
        case ':':
            return isToken(tempToken, ":");
        case ',':
            return isToken(tempToken, ",");
        default:
            tokenBuffer.push_back(character);
            tempToken.type = NOT_FOUND;
            return tempToken;
    }
}

Token Lexer::isToken(Token &token, const std::string &endingChar) {
    if (endingChar != " " && endingChar != "\n") {
        auto endingToken = new Token;
        endingToken->type = tokens[endingChar];
        endingToken->value = std::string(endingChar);
        token.endingToken = endingToken;
    }

    if (!tokenBuffer.empty()) {
        std::string tokenChars = std::string(tokenBuffer.begin(), tokenBuffer.end());
        try {
            TokenType firstToken = tokens.at(tokenChars);
            token.type = firstToken;
        } catch (const std::out_of_range &oor) {
            token.type = IDENTIFIER;
        }
        token.value = tokenChars;
        tokenBuffer.clear();
        return token;
    }
    token.type = NOT_FOUND;
    return token;
}

void Lexer::insertTokens() {
    tokens["if"] = IF;
    tokens["else"] = ELSE;
    tokens[";"] = SEMI_COLON;
    tokens["["] = LEFT_SQUARE_BRACKET;
    tokens["]"] = RIGHT_SQUARE_BRACKET;
    tokens["("] = LEFT_PARENTHESES;
    tokens[")"] = RIGHT_PARENTHESES;
    tokens[":"] = COLON;
    tokens[","] = COMMA;
}

std::vector<char> Lexer::readFile(const std::string &fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return std::vector<char>(content.begin(), content.end());
}