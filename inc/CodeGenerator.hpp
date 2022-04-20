#pragma once

class CodeGenerator{
public:
    enum Lang {JAVA = 0, C_PLUS_PLUS = 1, PHP = 2};
    CodeGenerator(Lang language) { m_language=language; }

    std::string generateCode(){
        switch(m_language) {
            case JAVA: someCodeRelatedThing();
            case C_PLUS_PLUS: someCodeRelatedThing();
            case PHP: someCodeRelatedThing();
        }
        throw new std::logic_error("Bad language");
    }

    std::string someCodeRelatedThing(){
        switch(m_language) {
            case JAVA: return "JAVA code";
            case C_PLUS_PLUS: return "C++ code";
            case PHP: return "PHP code";
        }
        throw new std::logic_error("Bad language");
    }

private:
    Lang m_language;
};
