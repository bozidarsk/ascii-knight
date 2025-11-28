#include "math.h"

int lfeq(double a, double b) 
{
	const double EPSILON = 1e-6;
	double diff = a - b;
	return (diff > 0) ? diff < EPSILON : -diff < EPSILON;
}

int feq(float a, float b) 
{
	const float EPSILON = 1e-6;
	float diff = a - b;
	return (diff > 0) ? diff < EPSILON : -diff < EPSILON;
}
