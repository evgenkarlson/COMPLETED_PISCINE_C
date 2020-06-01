/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FT_DOOR_H
# define  __FT_DOOR_H
# include <unistd.h>
# define OPEN 1
# define CLOSE 0
# define TRUE 1
# define EXIT_SUCCESS 0

typedef int     t_bool;
typedef struct  s_door
{
    int state;
}               t_door;

void	ft_putstr(char *str);
void	close_door(t_door *door);
void	open_door(t_door *door);
t_bool	is_door_open(t_door *door);
t_bool	is_door_close(t_door* door);

#endif