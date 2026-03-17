#pragma once
#include <string>
#include <vector>

struct Token {
    std::string type;
    std::string value;
    int col;
    int ln;

    Token();
    Token(std::string t, int c, int l, std::string v = "");
};

int lex(const char* input, std::vector<Token>& tkn) {}