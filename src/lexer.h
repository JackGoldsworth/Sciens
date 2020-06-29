#include "fstream"
#include <vector>

class Lexer {
public:
    std::vector<char> tokenBuffer;
    explicit Lexer(const std::string& fileName);
    void analyzeFile();
private:
    int lineNumber;
    std::vector<char> contents;
    bool isToken();
    void syntaxError(char character);
    static std::vector<char> readFile(const std::string& fileName);
};
