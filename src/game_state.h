#ifndef GAME_STATE_H_1e2af3c5
#define GAME_STATE_H_1e2af3c5

#include "logger.h"
#include "tile.h"

void game_state_init();
void game_state_reset();

uint8_t game_state_get_tile_amounts(struct tile t);
uint8_t (*game_state_get_tile_amounts_p())[N_NUMBERS];

/* void game_state_draw_tile(); */
void game_state_remove_tile(struct tile t);

#endif
