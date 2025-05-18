#ifndef HAND_H_1e2af3c5
#define HAND_H_1e2af3c5

#include "logger.h"
#include "tile.h"

#include <stdbool.h>

#define N_HAND 13

void hand_discard_tile(struct tile hand[N_HAND], struct tile in, uint8_t out);
bool hand_is_ready(struct tile hand[N_HAND]);

#endif
