#include "lexer.h"
#include "token.h"


Lexer::Lexer(const std::string &fileName) {
    contents = readFile(fileName);
    lineNumber = 0;
}

void Lexer::analyzeFile() {
    char character;
    while (character = *contents) {
        contents++;
        next(character);
    }
}

char* Lexer::readFile(const std::string& fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return (char*) content.c_str();
}

void Lexer::next(const char& character) {
    if(character == '\n') {
        lineNumber++;
        return;
    }
}