#ifndef LOGGER_H_1e2af3c5
#define LOGGER_H_1e2af3c5

#include <stdio.h>

typedef enum {
	NONE,
	FATAL,
	ERROR,
	DEBUG,
	INFO
} loglevel_t;

/* this needs to be a macro because it needs to access __func__ etc */
#define log(LOGLEVEL, fmt, ...) 						\
	do {									\
		if ((LOGLEVEL) <= get_loglevel()				\
				&& (LOGLEVEL) != NONE) { 			\
			fprintf(stdout, "%s() (%s:%d): " fmt, __func__,		\
					__FILE__, __LINE__, __VA_ARGS__);	\
			fprintf(stdout, "\n");					\
		}								\
	} while (0)

loglevel_t get_loglevel();
void set_loglevel(loglevel_t l);

#endif
