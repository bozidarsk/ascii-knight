#include <stdio.h>

#include "vectors.h"

int main() 
{
	float2 a = f2new(1, 2);
	float2 b = f2new(-1, 1);
	float2 c = f2add(a, b);
	c = f2add(c, b);

	printf("x=%f y=%f\n", c.x, c.y);

	return 0;
}
