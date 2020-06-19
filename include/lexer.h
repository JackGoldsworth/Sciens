#include "fstream"

class Lexer {
public:
    std::string contents;
    Lexer(const std::string& fileName);
    void analyzeFile();
private:
    std::string readFile(const std::string& fileName);
};
