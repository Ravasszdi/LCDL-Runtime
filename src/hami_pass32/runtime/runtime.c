#include "runtime.h"

void runtime(int memstacka[]){
    for (int i = 0; i<MEM_SIZE; i++) {
        if (i==0||i%4==0) {
            printf("\n");
        }else {
            printf("\t");
        }
        printf("%d : %x",i,*(memstacka+i));
    }
    printf("\n");
}
