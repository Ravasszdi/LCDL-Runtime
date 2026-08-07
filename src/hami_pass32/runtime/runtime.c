#include "runtime.h"

static int program_stack_counter = 0;
#define psc program_stack_counter

static int registers[REG_SIZE];
#define reg registers

void runtime(ops ops_list[]){
	for (psc = 0; ops_list[psc].ops != END; psc++) {

	}
}

void reg_dump(){
	for (int i = 0; i<REG_SIZE; i++) {
        if (i==0||i%4==0) {
            printf("\n");
        }else {
            printf("\t");
        }
        printf("r%x : 0x%00.8x",i,reg[i]);
    }
    printf("\n");
}
