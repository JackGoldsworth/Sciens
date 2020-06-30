#include "fstream"
#include "token.h"
#include <vector>

class Lexer {
public:
    std::vector<char> tokenBuffer;
    std::vector<char> contents;
    int lineNumber;

    explicit Lexer(const std::string &fileName);

    TokenType next();

private:
    int currentChar;

    bool isToken();

    static std::vector<char> readFile(const std::string &fileName);
};
