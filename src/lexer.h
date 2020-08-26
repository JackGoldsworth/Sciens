#include "fstream"
#include "token.h"
#include <vector>
#include <unordered_map>
#include <utility>

struct Token {
    int lineNumber;
    int charNumber;
    std::string value;
    TokenType type;
    Token *endingToken = nullptr;
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