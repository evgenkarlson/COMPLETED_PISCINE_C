/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: IHaveNoClueI <ctfx337@gmail.com>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/15 13:30:28 by IHaveNoClueI   #+#    #+#                */
/*   Updated: 2018/10/16 13:51:16 by IHaveNoClueI  ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_solver()
{
    char empty;
    char obstacle;
    char full;

    /* ascii = 46 */
    empty = ".";
    /* ascii = 111 */
    obstacle = "o";
    /* ascii = 120 */
    full = "x";

    int ascii_dot = (int)'.';
    int ascii_o = (int)'o';
    int ascii_x = (int)'x';

    ascii_dot = ascii_dot - ascii_dot + 0;
    ascii_o = ascii_o - ascii_o + 1;
    ascii_x = ascii_x - ascii_x + 2;
}
