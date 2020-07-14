#include "fstream"
#include "token.h"
#include <vector>
#include <unordered_map>
#include <utility>

struct EndingToken {
    std::string value;
    TokenType type;
};

struct Token {
    std::string value;
    TokenType type;
    EndingToken *endingToken = nullptr;
};

class Lexer {
public:
    std::vector<char> tokenBuffer;
    std::vector<char> contents;
    std::unordered_map<std::string, TokenType> tokens;

    int lineNumber;

    explicit Lexer(const std::string &fileName);

    Token next();

private:

    int currentChar;

    Token isToken(Token &token, const std::string &endingChar);

    void insertTokens();

    static std::vector<char> readFile(const std::string &fileName);
};