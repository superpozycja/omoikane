#include "game_state.h"

static uint8_t tile_amounts[N_SUITS][N_NUMBERS];

static void init_tile_amounts()
{
	log(INFO, "initializing tile amounts");
	memset(tile_amounts, 0x04, N_SUITS * N_NUMBERS);
	tile_amounts[N_SUITS - 1][0] = 0;
	tile_amounts[N_SUITS - 1][8] = 0;
	tile_amounts[N_SUITS - 1][9] = 0;
}

void game_state_init()
{
	log(INFO, "initializing game state");
	init_name_array();
	init_tile_amounts();
}

void game_state_reset()
{
	init_tile_amounts();
}

/* consider making this inline but the difference seems negligible */
uint8_t get_tile_amounts(struct tile t)
{
	return tile_amounts[t.suit][t.number];
}

/* for fast access and cloning, this is needed for threaded search */
uint8_t (*get_tile_amounts_p())[N_NUMBERS]
{
	return tile_amounts;
}

void game_state_remove_tile(struct tile t)
{
	if(tile_amounts[t.suit][t.number])
		tile_amounts[t.suit][t.number]--;
}
