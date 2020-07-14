enum TokenType {
    IF,                   // if
    ELSE,                 // else
    GREATER_THAN,         // >
    LESS_THAN,            // <
    GREATER_THAN_EQUAL,   // >=
    LESS_THAN_EQUAL,      // <=

    INT_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    IDENTIFIER,

    SEMI_COLON,           // ;
    COLON,                // :
    LEFT_CURLY_BRACKET,   // {
    RIGHT_CURLY_BRACKET,  // }
    LEFT_SQUARE_BRACKET,  // [
    RIGHT_SQUARE_BRACKET, // ]
    LEFT_PARENTHESES,     // (
    RIGHT_PARENTHESES,    // )
    COMMA,                // ,

    WRAP,                 // wrap
    FUNCTION,             // fun
    LET,                  // let
    println,              // println

    EOF_TOKEN,
    NOT_FOUND
};