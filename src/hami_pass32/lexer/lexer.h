#include "./../../libs.h"
#include "./../../communs.h"

enum e_ops {
    NOP,    //0
    END,    //1
    AND,    //2
    OR,     //3
    NOT,    //4
    XOR,    //5
    EQL,    //6
    ADD,    //7
    SUB,    //8
    MUL,    //9
    DIV,    //10
    MOD,    //11
    MOV,    //12
    SHR,    //13
    SHL,    //14
    IF,     //15
};

union ref_literal_type{
    int literal;
    int referens;
};

struct ops {
    enum e_ops  ops;
    union ref_literal_type a;
    union ref_literal_type b;
    union ref_literal_type c;
};


struct ops* lexer(char[]);
