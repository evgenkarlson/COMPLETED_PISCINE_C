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
