#include "./../libs.h"

// Byte
#define ARENA_SIZE 1024*2
#define ALIGNMENT 4

#define ARENA_AMOUNT 16

typedef int arena_id;

typedef struct {
    u_int8_t arena[ARENA_SIZE];
    int used_amount;
    bool in_use;
} arena;

void* a_alloc(arena_id id, int byte_amount);
void a_free(arena_id id);
arena_id a_find_free();
