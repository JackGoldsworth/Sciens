#include "lexer.h"

int main() {
    Lexer lexer(R"(C:\Users\xboxl\CLionProjects\Aerx\examples\example.arx)");
    lexer.analyzeFile();
    return 0;
}
