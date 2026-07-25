#include "./../libs.h"

// Byte
#define ARENA_SIZE 1024*2
#define ALIGNMENT 4

#define ARENA_AMOUNT 16

#define FREE 0
#define IN_USE 1
#define RESERVED 2

typedef int arena_id;

typedef struct {
    u_int8_t arena[ARENA_SIZE];
    int used_amount;
    char usege_status;
} arena;

void* a_alloc(arena_id id, int byte_amount);
arena_id a_reserve();
void a_free(arena_id id);
arena_id a_find_free();
