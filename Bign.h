#pragma once
#include <stdio.h>
#define Length 10000

typedef struct bign
{
	int num[1000] = { 0 };
	int len = 0;
}bign;

int* BIGN_mult(int* a, int b,int *len,int *len0)
{
	int *c, lenc = 0;
	c = (int*)malloc(Length * sizeof(int));
	int carry = 0;
	for (int i = 0; i < *len; i++)
	{
		int tmp = a[i] * b + carry;
		c[lenc++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0)
	{
		c[lenc++] = carry % 10;
		carry /= 10;
	}
	*len0 = lenc;
	return c;
}