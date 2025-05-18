#include "hand.h"

void hand_discard_tile(struct tile hand[N_HAND], struct tile in, uint8_t out)
{
	if (out > 13)
		return;

	(hand + out)->suit = in.suit;
	(hand + out)->number = in.number;
}
