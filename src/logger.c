#include "logger.h"

static loglevel_t level = NONE;

loglevel_t get_loglevel()
{
	return level;
}

void set_loglevel(loglevel_t l)
{
	level = l;
}
