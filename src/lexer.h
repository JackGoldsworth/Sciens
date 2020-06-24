#include "fstream"

class Lexer {
public:
    char* contents;
    Lexer(const std::string& fileName);
    void analyzeFile();
private:
    int lineNumber;
    char* readFile(const std::string& fileName);
    void next(const char& character);
};
