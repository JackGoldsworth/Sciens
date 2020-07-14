#include "fstream"
#include "token.h"
#include <vector>
#include <unordered_map>
#include <utility>

class Lexer {
public:
    std::vector<char> tokenBuffer;
    std::vector<char> contents;
    std::unordered_map<std::string, TokenType> tokens;

    int lineNumber;

    explicit Lexer(const std::string &fileName);

    std::pair<TokenType, TokenType> next();

private:

    int currentChar;

    std::pair<TokenType, TokenType> isToken(TokenType type);
    void insertTokens();
    static std::vector<char> readFile(const std::string &fileName);
};
