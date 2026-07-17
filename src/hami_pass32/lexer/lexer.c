#include "lexer.h"

struct ops make_ops();
enum e_ops get_ops(char text[]);
bool str_eql(char a[], char b[]);
union ref_literal_type ref_literal_parser(char text[]);
int num_parser(char number[], int base);

static int lexer_group;

struct ops* lexer(char inst_list[]){

    lexer_group = a_find_free();

    int inst_size = 0;
    for (int i = 0; inst_list[i]!='\0'; i++) {
        if (inst_list[i]==';') {
            inst_size++;
        }
    }

    struct ops* op_list = a_alloc(lexer_group, sizeof(struct ops)*inst_size);
    int start = 0;
    for (int i = 0; inst_list[i]!='\0'; i++) {
        if(inst_list[i]==';'){

        }
        if (inst_list[i]==' ') {

        }
    }

    return op_list;
}

enum e_ops get_ops(char text[]){
    if (str_eql(text, "nop")) {
        return NOP;
    } else if (str_eql(text, "end")) {
        return END;
    } else if (str_eql(text, "and")) {
        return AND;
    } else if (str_eql(text, "or")) {
        return OR;
    } else if (str_eql(text, "not")) {
        return NOT;
    } else if (str_eql(text, "xor")) {
        return XOR;
    } else if (str_eql(text, "eql")) {
        return EQL;
    } else if (str_eql(text, "add")) {
        return ADD;
    } else if (str_eql(text, "sub")) {
        return SUB;
    } else if (str_eql(text, "mul")) {
        return MUL;
    } else if (str_eql(text, "div")) {
        return DIV;
    } else if (str_eql(text, "mod")) {
        return MOD;
    } else if (str_eql(text, "mov")) {
        return MOV;
    } else if (str_eql(text, "shr")) {
        return SHR;
    } else if (str_eql(text, "shl")) {
        return SHL;
    } else if (str_eql(text, "if")) {
      return IF;
    } else {
      return NOP;
    }
}

bool str_eql(char a[], char b[]){
    int i = 0;
    while ((a[i]!='\0'||b[i]!='\0')&&(a[i]==b[i])) {
        i++;
    }
    return a[i]=='\0' && b[i]=='\0';
}

union ref_literal_type ref_literal_parser(char text[]){
    union ref_literal_type num;
    bool is_ref = *text=='<';
    int base = 0;
    switch (text[1]) {
        case 'b': base = 2;
        case 'o': base = 8;
        case 'd': base = 10;
        case 'x': base = 16;
        default: base = 10;
    }
    if (is_ref) {
        num.referens = num_parser(text, base);
    } else {
        num.literal = num_parser(text, base);
    }
    return num;
}

int num_parser(char number[], int base){
    int num = 0;
    int i = 3;
    for (i = 0; number[i]=='\0'; i++){}
    for(; i>=3; i--){
        switch (number[i]) {
            default: num += 0;
            case '1': num += 1;
            case '2': num += 2;
            case '3': num += 3;
            case '4': num += 4;
            case '5': num += 5;
            case '6': num += 6;
            case '7': num += 7;
            case '8': num += 8;
            case '9': num += 9;
            case 'a': num += 10;
            case 'b': num += 11;
            case 'c': num += 12;
            case 'd': num += 13;
            case 'e': num += 14;
            case 'f': num += 15;
        }
        num *= base;
    }
    return num;
}
