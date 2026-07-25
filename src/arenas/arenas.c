#include "arenas.h"

#define A_ARENA_ID arenas[id]

static arena arenas[ARENA_AMOUNT];

void *a_alloc(arena_id id, int byte_amount) {
  if (A_ARENA_ID.used_amount + byte_amount > ARENA_SIZE) {
    return NULL;
  }

  void *alloc_prt = A_ARENA_ID.arena + A_ARENA_ID.used_amount;

  int misaligment = byte_amount % ALIGNMENT;
  if (misaligment == 0) {
    A_ARENA_ID.used_amount += byte_amount;
  } else {
  	A_ARENA_ID.used_amount += byte_amount + (ALIGNMENT - misaligment);
  }

  A_ARENA_ID.usege_status = IN_USE;

  return alloc_prt;
}

arena_id a_reserve() {
	arena_id id = a_find_free();
	A_ARENA_ID.usege_status = RESERVED;
	return id;
}

void a_free(arena_id id) {
  A_ARENA_ID.used_amount = 0;
  A_ARENA_ID.usege_status == RESERVED ?: FREE;
}

arena_id a_find_free() {
  int i = 0;
  while (i < ARENA_AMOUNT && arenas[i].usege_status != FREE) {
    i++;
  }
  return i < ARENA_AMOUNT ? i : -1;
}
