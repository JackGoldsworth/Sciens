#include "lexer.h"

int main() {
    Lexer lexer(R"(C:\Users\xboxl\CLionProjects\Sciens\examples\example.arx)");
    lexer.analyzeFile();
    return 0;
}
