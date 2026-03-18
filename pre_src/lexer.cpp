#include <OllinAPI/Ollin.h>
#include <OllinAPI/lexer.h>


Token::Token() : type(Token::Type::UNKNOWN), value(""), col(0), ln(0) {}
Token::Token(Token::Type t, int c, int l, std::string v) : type(t), value(std::move(v)), col(c), ln(l) {}

const char* Token::toString(Token::Type t) {
    switch (t) {
        #define GENERATE_STRING(name) case Token::Type::name: return #name;
        TOKEN_TYPES(GENERATE_STRING)
        #undef GENERATE_STRING
        
        default: return "INVALID";
    }
}


int lex(const char* input, std::vector<Token>& tkn) {
    const char* YYCURSOR = input;
    const char* start;
    int ln = 1;
    int col = 1;


    while (*YYCURSOR) {
        start = YYCURSOR;

        /*!re2c
            re2c:yyfill:enable = 0;
            re2c:define:YYCTYPE = "unsigned char";

            [ \t]+ {
                col += (YYCURSOR - start);
                continue;
            }

            [\r?\n] {
                col = 1;
                ln++;
                tkn.emplace_back(Token::Type::LN, ln, col);
                continue;
            }

            ";"{
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::SEMICOLON, ln, col);
                continue;
            }

            "(" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::LPARENT, ln, col);
                continue;
            }


            ")" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::RPARENT, ln, col);
                continue;
            }

            "{" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::LBRACE, ln, col);
                continue;
            }


            "}" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::RBRACE, ln, col);
                continue;
            }

            "fn" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::FN, ln, col);
                continue;
            }

            "int" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::INT, ln, col);
                continue;
            }

            "print" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::PRINT, ln, col);
                continue;
            }

            "static" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::STATIC, ln, col);
                continue;
            }

            "string" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::STRING, ln, col);
                continue;
            }

            "class" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::CLASS, ln, col);
                continue;
            }

            "public" {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::PUBLIC, ln, col);
                continue;
            }

            [0-9]+ {
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::NUM, ln, col, std::string(start, YYCURSOR - start));
                continue;
            }

            [=+\-*%/<>!&|^~]{
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.emplace_back(Token::Type::OPERATOR, ln, col, std::string(start, YYCURSOR - start));
                continue;
            }

            [a-zA-Z_][a-zA-Z0-9_]* {
                std::string m(start, YYCURSOR - start);
                col += (YYCURSOR - start);
                tkn.emplace_back(Token::Type::IDENT, ln, col, std::string(start, YYCURSOR - start));
                continue;
            }

            "\"" ( "\\\"" | [^"] )* "\"" {
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.emplace_back(Token::Type::STRA, ln, col, std::string(start, YYCURSOR - start));
                continue;
            }

            "'" ( "\\'" | [^'] )* "'"  {
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.emplace_back(Token::Type::STRB, ln, col, std::string(start, YYCURSOR - start));
                continue;
            }

            * {
                col += (YYCURSOR - start);
                ++YYCURSOR;
                continue;
            }
        */
    }

    return 0;
}