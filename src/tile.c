#include "tile.h"

static bool name_array_initialized = false;

static const char *suit_names[] = {
	"dots",
	"bamboo",
	"character",
	"",	/* honors; they all have distinct names */
};

static const char *suit_names_romaji[] = {
	"pinzu",
	"sozu",
	"manzu",
	"",	/* honors; they all have distinct names */
};

static const char *suit_names_short[] = {
	"p",
	"s",
	"m",
	"z",
};

static const char *honor_names[] = {
	"east",
	"south",
	"west",
	"north",
	"white dragon",
	"green dragon",
	"red dragon",
};

/*
 * since it's impractical to just list out every combination of tiles, an
 * array is instead populated on first call to get_tile_name(). this eliminates
 * the need of any further allocations, simplifying the interface and
 * preventing potential mem leaks
 */

/* three star programming c; */
static char ***name_array;
static char ***name_array_short;

/*
 * this will be visible for the entire duration of the program, so it's alright
 * not to free
 * */
static void __init_name_array_helper(char ***ar)
{
	unsigned long n_suit = sizeof(suit_names)/sizeof(suit_names[0]);
	unsigned long n_numbers = 10;	/* 1-9 + red for number tiles, 7 honors */
	int i, j;

	/* number suits */
	for (i = 0; i < n_suit - 1; i++) {

		ar[i] = (char **) malloc(n_numbers * sizeof(char *));
		if (!ar[i])
			log(ERROR, "malloc() error");

		/* unroll the first iteration to handle red five edge case */
		ar[i][0]= (char *) malloc(32 * sizeof(char));

		if (!ar[i][0])
			log(ERROR, "malloc() error");
		if (ar == name_array) {
			strcat(ar[i][0], "red 5 ");
			strcat(ar[i][0], suit_names[i]);
		} else {
			snprintf(ar[i][0], 32, "%d", 0);
			strcat(ar[i][0], suit_names_short[i]);
		}

		for(j = 1; j < n_numbers; j++) {
			ar[i][j]= (char *) malloc(32 * sizeof(char));
			if (!ar[i][j])
				log(ERROR, "malloc() error");

			if (ar == name_array)
				snprintf(ar[i][j], 32, "%d %s", j, suit_names[i]);
			else
				snprintf(ar[i][j], 32, "%d%s", j, suit_names_short[i]);
		}
	}

	/* honors */
	ar[n_suit - 1] = (char **) malloc(n_numbers * sizeof(char *));
	if (!ar[n_suit - 1])
		log(ERROR, "malloc() error");

	for (j = 0; j < n_numbers; j++) {
		ar[n_suit - 1][j]= (char *) malloc(32 * sizeof(char));

		if (j < 1 || j > 7) {
			strcat(ar[n_suit - 1][j], "invalid");
			continue;
		}

		if (ar == name_array)
			snprintf(ar[n_suit - 1][j], 32, "%s", honor_names[j-1]);
		else
			snprintf(ar[n_suit - 1][j], 32, "%d%s", j, suit_names_short[i]);
	}
}

static void __init_name_array()
{
	unsigned long n_suit = sizeof(suit_names)/sizeof(suit_names[0]);

	name_array = (char ***) malloc(n_suit * sizeof(char **));
	name_array_short = (char ***) malloc(n_suit * sizeof(char **));

	if (!name_array)
		log(ERROR, "malloc() error");

	if (!name_array_short)
		log(ERROR, "malloc() error");


	__init_name_array_helper(name_array);
	__init_name_array_helper(name_array_short);
	name_array_initialized = true;
}

const char *get_tile_name(const struct tile *t)
{
	if (!name_array_initialized)
		__init_name_array();

	return name_array[t->suit][t->number];
}

const char *get_tile_name_short(const struct tile *t)
{
	if (!name_array_initialized)
		__init_name_array();

	return name_array_short[t->suit][t->number];
}
