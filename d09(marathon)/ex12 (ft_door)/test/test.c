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


#include "ft_door.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

void	open_door(t_door *door)
{
    ft_putstr("Door opening...\n");
    door->state = OPEN;
}

void	close_door(t_door *door)
{
    ft_putstr("Door closing...\n");
    door->state = CLOSE;
}

t_bool	is_door_open(t_door *door)
{
    ft_putstr("Door is open ?\n");
    return(door->state = OPEN);
}

t_bool	is_door_close(t_door* door)
{
    ft_putstr("Door is close ?\n");
    return(door->state = CLOSE);
}


int main()
{
    t_door	door;

    open_door(&door);
    if (is_door_close(&door))
        open_door(&door);
    if (is_door_open(&door))
        close_door(&door);
    if (door.state == OPEN)
        close_door(&door);
    return (EXIT_SUCCESS);
}
