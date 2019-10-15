#pragma once
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Bign.h"

int IsTheNumber(const int N)
{
	int t = sqrt(N);
	int num[10];
	int i = 0, flag = 0, n = N;
	if (t * t == N)
	{
		t = 10;
		while (n / t)
		{
			num[i++] = n % t;
			n /= t;
		}
		num[i] = n;
		for (int j = 0; j <= i; j++)
		{
			flag = 0;
			for (int k = j + 1; k <= i; k++)
				if (num[j] == num[k])
					flag++;
			if (flag == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

/*
int Factorial(const int N)
{
	int re = 1;
	for (int i = 1; i <= N; i++)
		re *= i;
	return re;
}
*/


double Factorial(double N)
{
	double re = 1;
	for (int i = 1; i <= N; i++)
		re *= i;
	return re;
}



void Print_Factorial(const int N)
{
	if (N < 0 || N > 1000)
	{
		printf("Invalid input\n");
		return;
	}
	else if (N == 0)
	{
		printf("%d\n", 1);
		return;
	}
	int t1,t2;
	int n[Length],re[Length],*re1,*n1;
	memset(n, 0, sizeof(n));
	n1 = n;
	n1[0] = 1;
	
	memset(re, 0, sizeof(re));
	re1 = re;
	int len1 = 1, len2 = 0;
	int* l1 = &len1, * l2 = &len2;
	for (int i = 1; i <= N; i++)
	{
		re1 = BIGN_mult(n1, i,l1,l2);
		n1 = re1;
		len1 = *l2;
	}
	len2 = *l2;
	while (len2 > 0)
	{
		printf("%d", re1[--len2]);
	}
	printf("\n");
}

