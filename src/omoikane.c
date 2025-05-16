/*
 * omoikane main binary
 */

#include "logger.h"

int main(int argc, char *argv[])
{
	set_loglevel(INFO);
	log(INFO, "hello from %s", argv[0]);

	return 0;
}
