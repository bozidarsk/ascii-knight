#include <stdio.h>

#include "vectors.h"
#include "console.h"

int main() 
{
	float2 a = f2new(1, 2);
	float2 b = f2new(-1, 1);
	float2 c = f2add(a, b);
	c = f2add(c, b);

	clear();
	setfgcolor(0x000000ff);
	printf("x=%f y=%f\n", c.x, c.y);

	setfgcolor(0x00ffffff);
	int2 winsize = consolesize();
	printf("%i %i\n", winsize.x, winsize.y);

	return 0;
}
