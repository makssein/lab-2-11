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

std::shared_ptr<CodeGenerator> codeFactory(enum Lang language) {
    switch(language) {
        case JAVA: return std::make_shared<JavaCodeGenerator>();
        case C_PLUS_PLUS: return std::make_shared<CppCodeGenerator>();
        case PHP: return std::make_shared<PHPCodeGenerator>();
        case GO: return std::make_shared<GoCodeGenerator>();
        case Kotlin: return std::make_shared<KotlinCodeGenerator>();
    }
    throw std::logic_error("Bad language");
}

