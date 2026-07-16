void nop_(){asm("nop");}
void and_(int* a,int* b, int* c){*c = *b & *a;}
void or_(int* a, int* b, int* c){*c = *b | *a;}
void not_(int* a, int* b){*b = !*a;}
void xor_(int* a, int* b, int* c){*c = *b ^ *a;}
void eql_(int* a, int* b, int* c){*c = *a == *b;}
void add_(int* a, int* b, int* c){*c = *a + *b;}
void sub_(int* a, int* b, int* c){*c = *a - *b;}
void mul_(int* a, int* b, int* c){*c = *a * *b;}
void div_(int* a, int* b, int* c){*c = *a / *b;}
void mod_(int* a, int* b, int* c){*c = *a % *b;}
void shr_(int* a, int* b){*a = *a >> *b;}
void shl_(int* a, int* b){*a = *a << *b;}
