#include <iostream>

#include "vectors.h"

int main() 
{
	float2 a = { .x = 1, .y = 2 };
	float2 b = { .x = -1, .y = 1 };
	float2 c = f2add(a, b);
	c = f2add(c, b);

	printf("x=%f y=%f\n", c.x, c.y);
}
