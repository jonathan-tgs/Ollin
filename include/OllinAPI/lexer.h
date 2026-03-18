#pragma once
#include <string>
#include <vector>
#include <Macros/token_types.h>


struct Token {
    enum class Type
    {
#define GENERATE_ENUM(name) name,
        TOKEN_TYPES(GENERATE_ENUM)
#undef GENERATE_ENUM
    };

    static const char* toString(Type t);

    Type type;
    std::string value;
    int col;
    int ln;

    Token();
    Token(Type t, int c, int l, std::string v = "");
};


int lex(const char* input, std::vector<Token>& tkn);