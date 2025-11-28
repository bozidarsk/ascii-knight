#include <math.h>

#include "vectors.h"
#include "mathf.h"

///////////////////////////////////////////////////////////////////////

float4 f4mul(float4 a, float x) 
{
	float4 c = { .x = a.x * x, .y = a.y * x, .z = a.z * x, .w = a.w * x };
	return c;
}

float4 f4div(float4 a, float x) 
{
	float4 c = { .x = a.x / x, .y = a.y / x, .z = a.z / x, .w = a.w / x };
	return c;
}

float4 f4add(float4 a, float4 b) 
{
	float4 c = { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w };
	return c;
}

float4 f4sub(float4 a, float4 b) 
{
	float4 c = { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .w = a.w - b.w };
	return c;
}

float f4lensq(float4 a) { return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w; }
float f4len(float4 a) { return sqrt(f4lensq(a)); }
float f4dist(float4 a, float4 b) { return f4len(f4sub(a, b)); }
float f4distsq(float4 a, float4 b) { return f4lensq(f4sub(a, b)); }

float4 f4norm(float4 a) 
{
	float4 zero = {0};
	float length = f4len(a);
	return !feq(length, 0) ? f4div(a, length) : zero;
}

int f4eq(float4 a, float4 b) { return feq(a.x, b.x) && feq(a.y, b.y) && feq(a.z, b.z) && feq(a.w, b.w); }
float f4dot(float4 a, float4 b) { return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; }

///////////////////////////////////////////////////////////////////////

float3 f3mul(float3 a, float x) 
{
	float3 c = { .x = a.x * x, .y = a.y * x, .z = a.z * x };
	return c;
}

float3 f3div(float3 a, float x) 
{
	float3 c = { .x = a.x / x, .y = a.y / x, .z = a.z / x };
	return c;
}

float3 f3add(float3 a, float3 b) 
{
	float3 c = { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
	return c;
}

float3 f3sub(float3 a, float3 b) 
{
	float3 c = { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z };
	return c;
}

float f3lensq(float3 a) { return a.x*a.x + a.y*a.y + a.z*a.z; }
float f3len(float3 a) { return sqrt(f3lensq(a)); }
float f3dist(float3 a, float3 b) { return f3len(f3sub(a, b)); }
float f3distsq(float3 a, float3 b) { return f3lensq(f3sub(a, b)); }

float3 f3norm(float3 a) 
{
	float3 zero = {0};
	float length = f3len(a);
	return !feq(length, 0) ? f3div(a, length) : zero;
}

int f3eq(float3 a, float3 b) { return feq(a.x, b.x) && feq(a.y, b.y) && feq(a.z, b.z); }
float f3dot(float3 a, float3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

float3 f3cross(float3 a, float3 b) 
{
	float3 c = { .x = a.y*b.z - a.z*b.y, .y = a.z*b.x - a.x*b.z, .z = a.x*b.y - a.y*b.x };
	return c;
}

///////////////////////////////////////////////////////////////////////

float2 f2mul(float2 a, float x) 
{
	float2 c = { .x = a.x * x, .y = a.y * x };
	return c;
}

float2 f2div(float2 a, float x) 
{
	float2 c = { .x = a.x / x, .y = a.y / x };
	return c;
}

float2 f2add(float2 a, float2 b) 
{
	float2 c = { .x = a.x + b.x, .y = a.y + b.y };
	return c;
}

float2 f2sub(float2 a, float2 b) 
{
	float2 c = { .x = a.x - b.x, .y = a.y - b.y };
	return c;
}

float f2lensq(float2 a) { return a.x*a.x + a.y*a.y; }
float f2len(float2 a) { return sqrt(f2lensq(a)); }
float f2dist(float2 a, float2 b) { return f2len(f2sub(a, b)); }
float f2distsq(float2 a, float2 b) { return f2lensq(f2sub(a, b)); }

float2 f2norm(float2 a) 
{
	float2 zero = {0};
	float length = f2len(a);
	return !feq(length, 0) ? f2div(a, length) : zero;
}

int f2eq(float2 a, float2 b) { return feq(a.x, b.x) && feq(a.y, b.y); }
float f2dot(float2 a, float2 b) { return a.x*b.x + a.y*b.y; }

float3 f2cross(float2 a, float2 b) 
{
	float3 c = { .x = 0, .y = 0, .z = a.x*b.y - a.y*b.x };
	return c;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int4 i4mul(int4 a, int x) 
{
	int4 c = { .x = a.x * x, .y = a.y * x, .z = a.z * x, .w = a.w * x };
	return c;
}

int4 i4div(int4 a, int x) 
{
	int4 c = { .x = a.x / x, .y = a.y / x, .z = a.z / x, .w = a.w / x };
	return c;
}

int4 i4add(int4 a, int4 b) 
{
	int4 c = { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z, .w = a.w + b.w };
	return c;
}

int4 i4sub(int4 a, int4 b) 
{
	int4 c = { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z, .w = a.w - b.w };
	return c;
}

int i4lensq(int4 a) { return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w; }
int i4len(int4 a) { return sqrt(i4lensq(a)); }
int i4dist(int4 a, int4 b) { return i4len(i4sub(a, b)); }
int i4distsq(int4 a, int4 b) { return i4lensq(i4sub(a, b)); }

int4 i4norm(int4 a) 
{
	int4 zero = {0};
	int length = i4len(a);
	return (length != 0) ? i4div(a, length) : zero;
}

int i4eq(int4 a, int4 b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w); }
int i4dot(int4 a, int4 b) { return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; }

///////////////////////////////////////////////////////////////////////

int3 i3mul(int3 a, int x) 
{
	int3 c = { .x = a.x * x, .y = a.y * x, .z = a.z * x };
	return c;
}

int3 i3div(int3 a, int x) 
{
	int3 c = { .x = a.x / x, .y = a.y / x, .z = a.z / x };
	return c;
}

int3 i3add(int3 a, int3 b) 
{
	int3 c = { .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
	return c;
}

int3 i3sub(int3 a, int3 b) 
{
	int3 c = { .x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z };
	return c;
}

int i3lensq(int3 a) { return a.x*a.x + a.y*a.y + a.z*a.z; }
int i3len(int3 a) { return sqrt(i3lensq(a)); }
int i3dist(int3 a, int3 b) { return i3len(i3sub(a, b)); }
int i3distsq(int3 a, int3 b) { return i3lensq(i3sub(a, b)); }

int3 i3norm(int3 a) 
{
	int3 zero = {0};
	int length = i3len(a);
	return (length != 0) ? i3div(a, length) : zero;
}

int i3eq(int3 a, int3 b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
int i3dot(int3 a, int3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

int3 i3cross(int3 a, int3 b) 
{
	int3 c = { .x = a.y*b.z - a.z*b.y, .y = a.z*b.x - a.x*b.z, .z = a.x*b.y - a.y*b.x };
	return c;
}

///////////////////////////////////////////////////////////////////////

int2 i2mul(int2 a, int x) 
{
	int2 c = { .x = a.x * x, .y = a.y * x };
	return c;
}

int2 i2div(int2 a, int x) 
{
	int2 c = { .x = a.x / x, .y = a.y / x };
	return c;
}

int2 i2add(int2 a, int2 b) 
{
	int2 c = { .x = a.x + b.x, .y = a.y + b.y };
	return c;
}

int2 i2sub(int2 a, int2 b) 
{
	int2 c = { .x = a.x - b.x, .y = a.y - b.y };
	return c;
}

int i2lensq(int2 a) { return a.x*a.x + a.y*a.y; }
int i2len(int2 a) { return sqrt(i2lensq(a)); }
int i2dist(int2 a, int2 b) { return i2len(i2sub(a, b)); }
int i2distsq(int2 a, int2 b) { return i2lensq(i2sub(a, b)); }

int2 i2norm(int2 a) 
{
	int2 zero = {0};
	int length = i2len(a);
	return (length != 0) ? i2div(a, length) : zero;
}

int i2eq(int2 a, int2 b) { return (a.x == b.x) && (a.y == b.y); }
int i2dot(int2 a, int2 b) { return a.x*b.x + a.y*b.y; }

int3 i2cross(int2 a, int2 b) 
{
	int3 c = { .x = 0, .y = 0, .z = a.x*b.y - a.y*b.x };
	return c;
}

///////////////////////////////////////////////////////////////////////
