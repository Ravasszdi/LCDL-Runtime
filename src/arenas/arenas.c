#include "arenas.h"

#define ALIGNMENT 4

static arena arenas[ARENA_AMOUNT];


void* a_alloc(int arena_id, int byte_amount){
    if (arenas[arena_id].used_amount + byte_amount > ARENA_SIZE) {
        return NULL;
    }

    void* alloc_prt = arenas[arena_id].arena + arenas[arena_id].used_amount;

    int misaligment = byte_amount % ALIGNMENT;
    if (misaligment == 0) {
        arenas[arena_id].used_amount += byte_amount;
    } else {
        arenas[arena_id].used_amount += byte_amount + (ALIGNMENT - misaligment);
    }

    arenas[arena_id].in_use = true;

    return alloc_prt;
}

void a_free(int arena_id){
    arenas[arena_id].used_amount = 0;
    arenas[arena_id].in_use = false;
}

arena_id a_find_free(){
    int i = 0;
    while (i < ARENA_AMOUNT && arenas[i].in_use) {
        i++;
    }
    return i < ARENA_AMOUNT? i : -1;
}
