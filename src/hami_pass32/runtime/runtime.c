#include "runtime.h"

void runtime(int memstacka[]){
    for (int i = 0; i<ARENA_SIZE; i++) {
        if (i==0||i%4==0) {
            printf("\n");
        }else {
            printf("\t");
        }
        printf("%x : 0x%00.8x",i,*(memstacka+i));
    }
    printf("\n");
}
