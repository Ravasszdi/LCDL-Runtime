void nop(){asm("nop");}
void and_(int* a,int* b, int* c){*c = *b & *a;}
void or_(int* a, int* b, int* c){*c = *b | *a;}
void not_(int* a, int* b){*b = !*a;}
void xor_(int* a, int* b, int* c){*c = *b ^ *a;}
void eql(int* a, int* b, int* c){*c = *a == *b;}
void add(int* a, int* b, int* c){*c = *a + *b;}
void sub(int* a, int* b, int* c){*c = *a - *b;}
void mul(int* a, int* b, int* c){*c = *a * *b;}
void div(int* a, int* b, int* c){*c = *a / *b;}
void mod(int* a, int* b, int* c){*c = *a % *b;}
void shr(int* a, int* b){*a = *a >> *b;}
void shl(int* a, int* b){*a = *a << *b;}
