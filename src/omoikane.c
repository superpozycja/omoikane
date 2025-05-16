/*
 * omoikane main binary
 */

#include <stdlib.h>

#include "logger.h"
#include "version.h"

int main(int argc, char *argv[])
{
	char *level = getenv("LOGLEVEL");
	if (level)
		set_loglevel(level);

	log(INFO, "hello from %s %d.%d.%d", argv[0],
	    VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

	return 0;
}
