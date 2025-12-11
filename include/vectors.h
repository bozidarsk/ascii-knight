#ifndef VECTORS_H
#define VECTORS_H

typedef struct float4 
{
	float x, y, z, w;
} float4, f4;

float4 f4new(float x, float y, float z, float w);
float4 f4add(float4 a, float4 b);
float4 f4sub(float4 a, float4 b);
float4 f4mul(float4 a, float x);
float4 f4div(float4 a, float x);
float f4lensq(float4 a);
float f4len(float4 a);
float4 f4norm(float4 a);
float f4dist(float4 a, float4 b);
float f4distsq(float4 a, float4 b);
int f4eq(float4 a, float4 b);
float f4dot(float4 a, float4 b);

typedef struct float3 
{
	float x, y, z;
} float3, f3;

float3 f3new(float x, float y, float z);
float3 f3add(float3 a, float3 b);
float3 f3sub(float3 a, float3 b);
float3 f3mul(float3 a, float x);
float3 f3div(float3 a, float x);
float f3lensq(float3 a);
float f3len(float3 a);
float3 f3norm(float3 a);
float f3dist(float3 a, float3 b);
float f3distsq(float3 a, float3 b);
int f3eq(float3 a, float3 b);
float f3dot(float3 a, float3 b);
float3 f3cross(float3 a, float3 b);

typedef struct float2 
{
	float x, y;
} float2, f2;

float2 f2new(float x, float y);
float2 f2add(float2 a, float2 b);
float2 f2sub(float2 a, float2 b);
float2 f2mul(float2 a, float x);
float2 f2div(float2 a, float x);
float f2lensq(float2 a);
float f2len(float2 a);
float2 f2norm(float2 a);
float f2dist(float2 a, float2 b);
float f2distsq(float2 a, float2 b);
int f2eq(float2 a, float2 b);
float f2dot(float2 a, float2 b);
float3 f2cross(float2 a, float2 b);

typedef struct int4 
{
	int x, y, z, w;
} int4, i4;

int4 i4new(int x, int y, int z, int w);
int4 i4add(int4 a, int4 b);
int4 i4sub(int4 a, int4 b);
int4 i4mul(int4 a, int x);
int4 i4div(int4 a, int x);
int i4lensq(int4 a);
int i4len(int4 a);
int4 i4norm(int4 a);
int i4dist(int4 a, int4 b);
int i4distsq(int4 a, int4 b);
int i4eq(int4 a, int4 b);
int i4dot(int4 a, int4 b);

typedef struct int3 
{
	int x, y, z;
} int3, i3;

int3 i3new(int x, int y, int z);
int3 i3add(int3 a, int3 b);
int3 i3sub(int3 a, int3 b);
int3 i3mul(int3 a, int x);
int3 i3div(int3 a, int x);
int i3lensq(int3 a);
int i3len(int3 a);
int3 i3norm(int3 a);
int i3dist(int3 a, int3 b);
int i3distsq(int3 a, int3 b);
int i3eq(int3 a, int3 b);
int i3dot(int3 a, int3 b);
int3 i3cross(int3 a, int3 b);

typedef struct int2 
{
	int x, y;
} int2, i2;

int2 i2new(int x, int y);
int2 i2add(int2 a, int2 b);
int2 i2sub(int2 a, int2 b);
int2 i2mul(int2 a, int x);
int2 i2div(int2 a, int x);
int i2lensq(int2 a);
int i2len(int2 a);
int2 i2norm(int2 a);
int i2dist(int2 a, int2 b);
int i2distsq(int2 a, int2 b);
int i2eq(int2 a, int2 b);
int i2dot(int2 a, int2 b);
int3 i2cross(int2 a, int2 b);


#endif
