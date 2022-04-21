#pragma once
enum Lang {
    JAVA = 0,
    C_PLUS_PLUS = 1,
    PHP = 2,
    GO = 3,
    Kotlin = 4
};

class CodeGenerator {
public:
    CodeGenerator() {}

    virtual ~CodeGenerator() {}

    std::string generateCode() {
        return "Result:\n\n " + someCodeRelatedThing();
    }

protected:
    virtual std::string someCodeRelatedThing() = 0;
};

class JavaCodeGenerator : public CodeGenerator{
public:
    JavaCodeGenerator() : CodeGenerator() {}
    virtual ~JavaCodeGenerator(){}

protected:
    std::string someCodeRelatedThing() override{
        return "class HelloWorld {\n"
               "    public static void main(String[] args) {\n"
               "        System.out.println(\"Hello World!\");\n"
               "    }\n"
               "}";
    }
};

class CppCodeGenerator : public CodeGenerator{
public:
    CppCodeGenerator() : CodeGenerator() {}
    virtual ~CppCodeGenerator(){}

protected:
    std::string someCodeRelatedThing() override{
        return "int main() {\n"
               "    std::cout << \"Hello World!\";\n"
               "    return 0;\n"
               "}";
    }
};

class PHPCodeGenerator : public CodeGenerator{
public:
    PHPCodeGenerator() : CodeGenerator() {}
    virtual ~PHPCodeGenerator(){}

protected:
    std::string someCodeRelatedThing() override{
        return "<?php echo 'Hello world!'; ?>";
    }
};

class GoCodeGenerator : public CodeGenerator{
public:
    GoCodeGenerator() : CodeGenerator() {}
    virtual ~GoCodeGenerator(){}

protected:
    std::string someCodeRelatedThing() override{
        return "func main() {\n"
               "    fmt.Println(\"Hello World\")\n"
               "}";
    }
};

class KotlinCodeGenerator : public CodeGenerator{
public:
    KotlinCodeGenerator() : CodeGenerator() {}
    virtual ~KotlinCodeGenerator(){}

protected:
    std::string someCodeRelatedThing() override{
        return "fun main(args : Array<String>) {\n"
               "    println(\"Hello, World!\")\n"
               "}";
    }
};

CodeGenerator* codeFactory(enum Lang language) {
    CodeGenerator* code = nullptr;
    switch(language) {
        case JAVA: return code = new JavaCodeGenerator();
        case C_PLUS_PLUS: return code = new CppCodeGenerator();
        case PHP: return code = new PHPCodeGenerator();
        case GO: return code = new GoCodeGenerator();
        case Kotlin: return code = new KotlinCodeGenerator();
    }
    throw std::logic_error("Bad language");
}

