/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: IHaveNoClueI <ctfx337@gmail.com>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/17 15:06:10 by IHaveNoClueI   #+#    #+#                */
/*   Updated: 2018/10/17 15:06:15 by IHaveNoClueI  ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int    ft_square(void)
{
    int i, j;
    int row, col;
    int square[row][col];
    char empty;
    char obstacle;
    char full;

    row = 1;
    col = 1;
    empty = '.';
    obstacle = 'o';
    full = 'x';

    int ascii_dot = (int)'.';
    int ascii_o = (int)'o';
    int ascii_x = (int)'x';

    ascii_dot = ascii_dot - ascii_dot + 0;
    ascii_o = ascii_o - ascii_o + 1;
    ascii_x = ascii_x - ascii_x + 2;

    while (i < square[row] && square[row] != '\n')
    {
        square[row++][col];
        i++;
    }
    return (i);

    while (i < square[col] && square[col] != '\n')
    {
        square[row][col++];
        j++;
    }
    return (j);
}
