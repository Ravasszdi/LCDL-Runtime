#include "main.h"

void loop();

int memstack[MEM_SIZE];

int main(){
//  void setup(){
    memstack[0] = 1;
    memstack[1] = 2;
    memstack[2] = 3;
    memstack[255] = 42;
// for testing we will *only* use an 8 bits system
//  }
    loop();
    printf("hello world!\n");
    return 0;
}


void loop(){
    runtime(memstack);
}
