#ifndef TILE_H_1e2af3c5
#define TILE_H_1e2af3c5

#include "logger.h"

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define N_SUITS 4
#define N_NUMBERS 10
#define N_HONORS 7

/*
 * this is actually 2 bytes on an m1 mac using clang 14.0.3, but this might
 * change depending on the setup. reconsider using a packed uint16_t instead
 *
 * also keep in mind that it's actually MORE efficient to just pass this by
 * value as 16 bits rather than a 64-bit pointer
 */

struct tile {
	uint8_t suit;
	uint8_t number;
};

void init_name_array();
const char *get_tile_name(const struct tile t);
const char *get_tile_name_short(const struct tile t);

#endif
