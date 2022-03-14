#include "ShuntingYardParser.h"
#include "AST.h"
#include <vector>
#include <string>
#include <iostream>

int main () {
    shuntingYardParser s;

    AST* tree = s.shuntInfix(s.splitExpression("4+(5^2)/2"));
    auto v = tree->Posttraverse();
    for (const std::string& vin : v) {
        std::cout << vin;
    }
    std::cout << std::endl;

}
