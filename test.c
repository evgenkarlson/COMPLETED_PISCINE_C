/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_HEIGHT 4
#define MATRIX_WIDTH 5

void static_array_print(int A[][MATRIX_WIDTH], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < MATRIX_WIDTH; j++)
			printf("%*d", 5, A[i][j]);
		printf("\n");
	}
}

void static_array_test(int N)
{
	int A[N][MATRIX_WIDTH];
	int x = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < MATRIX_WIDTH; j++)
		{
			A[i][j] = x;
			x += 1;
		}
	}
	static_array_print(A, N);

	// memory investigation
	printf("\n Direct memory access:\n");
	for (int *p = (int *)A; p < (int *)A + 20; p++)
		printf("%3d", *p);
	printf("\n\n");
}

void dynamic_array_print(int **A, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%*d", 5, A[i][j]);
		}
		printf("\n");
	}
}

// return pointer on 2d dynamic array
// !allocates memory -> to be freed later

int **dynamic_array_alloc(int N, int M)
{
	int **A = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		A[i] = (int *)malloc(M * sizeof(int));
	}
	return A;
}

void dynamic_array_free(int **A, int N)
{
	for (int i = 0; i < N; i++)
	{
		free(A[i]);
	}
	free(A);
}

void dynamic_array_test(int N, int M)
{
	int **A = dynamic_array_alloc(N, M);
	int x = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = x;
			x += 1;
		}
	}
	dynamic_array_print(A, N, M);

	// memory investigation
	printf("\n Pointers to lines: ");
	for (int **p = A; p < A + 3; p++)
		printf("%10ld", (long int)*p);

	printf("\n Direct memory access:\n");
	for (int *p = (int *)*A; p < (int *)*A + 25; p++)
		printf("%d\t", *p);
	dynamic_array_free(A, N);
	printf("\n");
}

int main()
{
	int matrix_height = 4;
	int matrix_width = 5;

	static_array_test(MATRIX_HEIGHT);
	dynamic_array_test(matrix_height, matrix_width);
	return 0;
}