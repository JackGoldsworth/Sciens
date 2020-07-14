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

    char endTokenBuffer;
    std::string identifierBuffer;

    int lineNumber;

    explicit Lexer(const std::string &fileName);

    TokenType next();

private:

    int currentChar;

    TokenType isToken();

    void insertTokens();

    static std::vector<char> readFile(const std::string &fileName);
};
