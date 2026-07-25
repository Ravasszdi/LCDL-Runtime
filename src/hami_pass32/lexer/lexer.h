#include "./../../libs.h"
#include "./../../arenas/arenas.h"

static int lexer_group;

typedef enum {
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
} e_ops;

typedef union {
    int literal;
    int referens;
} ref_literal_type;

typedef struct{
    e_ops  ops;
    ref_literal_type a;
    ref_literal_type b;
    ref_literal_type c;
} ops ;


ops* lexer(char[]);
