#include "logger.h"

static enum loglevel_t level = NONE;

static const char *loglevel_names[] = {
	"NONE",
	"FATAL",
	"ERROR",
	"DEBUG",
	"INFO",
};


enum loglevel_t get_loglevel()
{
	return level;
}

void set_loglevel(const char *name)
{
	int i;

	for (i = 0; i < sizeof(loglevel_names)/sizeof(loglevel_names[0]); i++) {
		if (!strncmp(name, loglevel_names[i], 5)) {
			level = (enum loglevel_t)i;
			return;
		}
	}
	level = 0;
}

void set_loglevel_t(enum loglevel_t l)
{
	level = l;
}
