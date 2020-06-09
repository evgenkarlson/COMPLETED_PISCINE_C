/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** **
**
**
**	• Напишите файл ft_door.h и исправьте следующий файл ft_door.c:
**
**------------------------------------------------------------------------------
**  	#include "ft_door.h"
**
**  	ft_putstr(char *c)
**		{
**			int	i = 0;
**
**			while(str[i])
**				write(1, str, i)
**		}
**
**  	ft_bool close_door(t_door *door)
**		{
**			ft_putstr(’Door closing...’);
**			state = CLOSE;
**			return (TRUE);
**		}
**
**  	void	is_door_open(t_door door)
**		{
**			ft_putstr("Door is open ?");
**			return(door->state = OPEN);
**		}
**
**  	ft_bool is_door_close(t_door* door)
**		{
**			ft_putstr("Door is close ?") ;
**		}
**------------------------------------------------------------------------------
**
**
**
**		• Вот пример main и вывода:
**------------------------------------------------------------------------------
**		$> cat main.c
**		#include <stdlib.h>
**		#include "ft_door.h"
**		
**		int main()
**		{
**			t_door	door
**		
**			open_door(&door);
**			if (is_door_close(&door))
**				open_door(&door);
**			if (is_door_open(&door))
**				close_door(&door);
**			if (door.state == OPEN)
**				close_door(&door);
**			return (EXIT_SUCCESS);
**		}
**		$>./ft_door | cat -e
**		Door opening...$
**		Door is close ?$
**		Door is open ?$
**		Door closing...$
**------------------------------------------------------------------------------
** ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_door.h"

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
	if (door->state == OPEN)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	if (door->state == CLOSE)
		return (TRUE);
	else
		return (FALSE);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
