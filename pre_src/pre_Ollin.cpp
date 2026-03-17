#include <Ollin.h>

int main() {

    std::ifstream file("test.ollin", std::ios::binary);

    std::string content(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    std::vector<Token> Tokens;
    int res = lex(content.data(), Tokens);
    
    if (res != 0) {
        return 1;
    }
    
    std::cout << "code :" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << content << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
    
    std::cout << "------------------------------" << std::endl;
    std::cout << "Token Zise: " << Tokens.size() << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;

    for (const Token& t : Tokens) {
        if (t.data.Value == "") {
            std::cout << "Type: " << t.type << " --- " << "(" << t.data.col << ", " << t.data.ln << ")" << std::endl;
        } else {
            std::cout << "Type: " << t.type << " | " << "Value: " << t.data.Value << " --- " << "(" << t.data.col << ", " << t.data.ln << ")" << std::endl;
        }
    }

    

    return 0;
}

