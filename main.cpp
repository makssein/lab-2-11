#include <iostream>
#include "inc/CodeGenerator.hpp"

int main() {
    CodeGenerator* code = codeFactory(JAVA);
    std::cout << code->generateCode() << std::endl;
    return 0;
}
