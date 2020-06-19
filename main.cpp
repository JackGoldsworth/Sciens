#include <iostream>
#include "lexer.h"

int main() {
    Lexer lexer(R"(C:\Users\xboxl\CLionProjects\Aerx\examples\example.arx)");
    std::cout << lexer.contents << std::endl;
    return 0;
}
