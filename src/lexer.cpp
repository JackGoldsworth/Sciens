#include "lexer.h"

Lexer::Lexer(const std::string &fileName) {
    contents = readFile(fileName);
}

void Lexer::analyzeFile() {

}

std::string Lexer::readFile(const std::string& fileName) {
    std::ifstream fileStream(fileName);
    std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    return content;
}