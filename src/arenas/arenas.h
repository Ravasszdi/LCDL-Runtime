#include "./../libs.h"

#define ARENA_SIZE 1024*2
#define ARENA_AMOUNT 16

typedef int arena_id;

typedef struct {
    u_int8_t arena[ARENA_SIZE];
    int used_amount;
    bool in_use;
} arena;

void* a_alloc(int arena_id, int byte_amount);
void a_free(int arena_id);
arena_id a_find_free();
