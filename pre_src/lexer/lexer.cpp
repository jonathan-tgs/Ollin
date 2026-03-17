#include <OllinAPI/Ollin.h>
#include <OllinAPI/lexer.h>

Token::Token() : type(""), value(""), col(0), ln(0) {}
Token::Token(std::string t, int c, int l, std::string v = "") : type(std::move(t)), value(std::move(v)), col(c), ln(l) {}

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
                tkn.push_back({"LN", ln, col)});
                continue;
            }

            ";"{
                col += (YYCURSOR - start);
                tkn.push_back({"SEMICOLON", Data(ln, col)});
                continue;
            }

            "(" {
                col += (YYCURSOR - start);
                tkn.push_back({"LPARENT", Data(ln, col)});
                continue;
            }


            ")" {
                col += (YYCURSOR - start);
                tkn.push_back({"RPARENT", Data(ln, col)});
                continue;
            }

            "{" {
                col += (YYCURSOR - start);
                tkn.push_back({"LBRACE", Data(ln, col)});
                continue;
            }


            "}" {
                col += (YYCURSOR - start);
                tkn.push_back({"RBRACE", Data(ln, col)});
                continue;
            }

            "fn" {
                col += (YYCURSOR - start);
                tkn.push_back({"FN", Data(ln, col)});
                continue;
            }

            "int" {
                col += (YYCURSOR - start);
                tkn.push_back({"INT", Data(ln, col)});
                continue;
            }

            "print" {
                col += (YYCURSOR - start);
                tkn.push_back({"PRINT", Data(ln, col)});
                continue;
            }

            "static" {
                col += (YYCURSOR - start);
                tkn.push_back({"STATIC", Data(ln, col)});
                continue;
            }

            "string" {
                col += (YYCURSOR - start);
                tkn.push_back({"STRING", Data(ln, col)});
                continue;
            }

            "class" {
                col += (YYCURSOR - start);
                tkn.push_back({"CLASS", Data(ln, col)});
                continue;
            }

            "public" {
                col += (YYCURSOR - start);
                tkn.push_back({"PUBLIC", Data(ln, col)});
                continue;
            }

            [0-9]+ {
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.push_back({"NUM", Data(ln, col, m)});
                continue;
            }

            [=+\-*%/<>!&|^~]{
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.push_back({"OPERATOR", Data(ln, col, m)});
                continue;
            }

            [a-zA-Z_][a-zA-Z0-9_]* {
                std::string m(start, YYCURSOR - start);
                col += (YYCURSOR - start);
                tkn.push_back({"IDENT", Data(ln, col, m)});
                continue;
            }

            "\"" ( "\\\"" | [^"] )* "\"" {
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.push_back({"STRING", Data(ln, col, m)});
                continue;
            }

            "'" ( "\\'" | [^'] )* "'"  {
                col += (YYCURSOR - start);
                std::string m(start, YYCURSOR - start);
                tkn.push_back({"STRING", Data(ln, col, m)});
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