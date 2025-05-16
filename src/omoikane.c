/*
 * omoikane main binary
 */

#include "logger.h"
#include "version.h"

int main(int argc, char *argv[])
{
	set_loglevel(INFO);
	log(INFO, "hello from %s %d.%d.%d", argv[0],
	    VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

	return 0;
}
