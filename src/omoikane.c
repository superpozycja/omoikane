/*
 * omoikane main binary
 */

#include <stdlib.h>

#include "logger.h"
#include "version.h"
#include "tile.h"
#include "game_state.h"

int main(int argc, char *argv[])
{
	char *level = getenv("LOGLEVEL");
	if (level)
		set_loglevel(level);

	game_state_init();

	log(INFO, "hello from %s %d.%d.%d", argv[0],
	    VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

	return 0;
}
