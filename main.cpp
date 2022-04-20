#include <iostream>
#include "inc/CodeGenerator.hpp"

int main() {
    std::shared_ptr<CodeGenerator> code = codeFactory(Kotlin);
    std::cout << code->generateCode() << std::endl;
    return 0;
}
