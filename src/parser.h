#include <string>
#include <list>
#include "lexer.h"

class Parser {
public:
    std::list<Token> tokenList;

    void parseFile(const std::string &fileName);
};