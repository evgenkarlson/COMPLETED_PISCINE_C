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
#include <time.h>


int fib(int n)
{
	static int cache[100] = {0};
	
	if (n <= 1)
		return n;
	if (cache[n] == 0)
		cache[n] = fib(n - 1) + fib(n - 2);
	return cache[n];
}

int fib_dynamic(int n)
{
	int	Fib[n + 1];
	Fib[0] = 0;
	Fib[1] = 1;
	for (int i = 2; i <= n; ++i)
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	return Fib[n];
}

int main(void)
{
	for (int n = 1; n < 50; n += 1)
	{
		clock_t	time1 = clock();
		int 	result = fib_dynamic(n);
		clock_t	time2 = clock();
		int delta_ms = (time2 - time1) * 1000 / CLOCKS_PER_SEC;

		if (n < 21)
			printf("fib(%d) = %d,\t\t time = %d ms\n",
				   n, result, delta_ms);
		else
			printf("fib(%d) = %d,\t time = %d ms\n",
				   n, result, delta_ms);
	}

	return 0;
}

/*
#include <unistd.h>

int		ft_compact(char **tab, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		while (*(tab + i))
			i++;
		j = i;
		length--;
		while (j < length)
		{
			*(tab + j) = *(tab + j + 1);
			j++;
		}
	}
	return (length);
}


int main(int argc, char *argv[])
{   
    int i;
    int j;

    ft_compact(argv, argc);
    
	i = 0;
    while (argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        i++;
    }
    return (0);
}
*/