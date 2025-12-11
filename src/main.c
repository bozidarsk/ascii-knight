#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "vectors.h"
#include "console.h"

#define GRAY 0xff7f7f7f
#define WHITE 0xffffffff
#define BLACK 0xff000000

static const char lheader[] = "HP: %i  SCORE: %i";
static const char rheader[] = "  (a/d - move, w - jump, ww - double jump, i/j/k/l - attack, ESC - exit)";

typedef struct object 
{
	union 
	{
		int2 position;
		struct { int x, y; };
	};

	uint32_t color;
	char sprite;
} object;

typedef struct map 
{
	union 
	{
		int2 size;
		struct { int width, height; };
	};

	int objectsCount;
	object *objects;

	uint32_t color;
} map;

void map_render(const map *map) 
{
	assert(map);
	assert(map->width > 0);
	assert(map->height > 0);

	clear();

	setbgcolor(map->color);
	setfgcolor(WHITE);

	char header[map->width + 1];
	snprintf(header, sizeof(header), lheader, 1 /* health */, 2 /* score */);

	int lheaderLength = strlen(header);
	int rheaderLength = sizeof(rheader) - 1;

	if (lheaderLength + rheaderLength <= map->width) 
	{
		printf(header);
		for (int i = map->width - (lheaderLength + rheaderLength); i > 0; i--) printf(" ");
		printf(rheader);
	}
	else if (lheaderLength <= map->width) 
	{
		printf(header);
		for (int i = map->width - lheaderLength; i > 0; i--) printf(" ");
	}
	else 
	{
		fprintf(stderr, "make the console wider, there is no space for headers\n");
		exit(1);
	}

	printf("\n");

	for (int y = 0; y < map->height; y++) 
	{
		for (int x = 0; x < map->width; x++) 
		{
			bool found = false;

			for (int i = 0; i < map->objectsCount; i++) 
			{
				if (map->objects[i].x != x || map->objects[i].y != y)
					continue;

				setfgcolor(map->objects[i].color);
				printf("%c", map->objects[i].sprite);
				found = true;
				break;
			}

			if (!found) 
			{
				setfgcolor(map->color);
				printf(" ");
			}
		}
	}

	fflush(stdout);
}

void map_generate(map *map) 
{
	assert(map);

	int2 consize = consolesize();
	consize.y--;

	assert(consize.x > 0);
	assert(consize.y > 0);

	map->size = consize;
	map->color = BLACK;
	map->objectsCount = 0;

	map->objectsCount += (2 * map->width) + (2 * map->height) - 4; // border
	map->objectsCount += 3; // attack animation
	// ...

	map->objects = (object*)malloc(map->objectsCount * sizeof(object));
	int index = 0;

	for (int x = 0; x < map->width; x++) 
	{
		map->objects[index].position = i2new(x, 0);
		map->objects[index].color = GRAY;
		map->objects[index].sprite = '#';
		index++;

		map->objects[index].position = i2new(x, map->height - 1);
		map->objects[index].color = GRAY;
		map->objects[index].sprite = '#';
		index++;
	}

	for (int y = 1; y < map->height - 1; y++) 
	{
		map->objects[index].position = i2new(0, y);
		map->objects[index].color = GRAY;
		map->objects[index].sprite = '#';
		index++;

		map->objects[index].position = i2new(map->width - 1, y);
		map->objects[index].color = GRAY;
		map->objects[index].sprite = '#';
		index++;
	}
}

int run(const map *map) 
{
	struct timespec tprev, tcurr;

	for (;;) 
	{
		timespec_get(&tcurr, TIME_UTC);
		double dt = (double)(tcurr.tv_sec - tprev.tv_sec) + (double)(tcurr.tv_nsec - tprev.tv_nsec)*1e-9;

		switch (input()) 
		{
			case 27:
				return 0;
		}

		// map_render(map);
		wait(100);
		tprev = tcurr;
	}

	return 0;
}

int main() 
{
	map map;
	map_generate(&map);

	hidecursor();
	int code = run(&map);
	showcursor();

	free(map.objects);
	return code;
}
