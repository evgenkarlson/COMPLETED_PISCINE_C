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
#include <unistd.h>

typedef int ft_bool;
#define TRUE 1
#define OPEN 1
#define CLOSE 0
#define EXIT_SUCCESS 0
typedef struct	s_door
{
	int	state;
}				t_door;
ft_bool	open_door(t_door *door);
ft_bool	close_door(t_door *door);
ft_bool	is_door_open(t_door *door);
ft_bool	is_door_close(t_door *door);


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




#ifndef FT_DOOR_H
# define FT_DOOR_H
# define OPEN 1
# define CLOSE 0
# define TRUE 1
# define EXIT_SUCCESS 0
# include <unistd.h>

typedef int	t_bool;

typedef struct	s_door {
	t_bool	state;
}				t_door;

void			ft_putstr(char *str);

t_bool			is_door_open(t_door *door);

t_bool			is_door_close(t_door *door);

void			close_door(t_door *door);

void			open_door(t_door *door);

#endif





/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef __FT_DOOR_H
# define __FT_DOOR_H

# include "ft_door.h"
# include <unistd.h>

# define TRUE	1
# define FALSE	0
# define OPEN	1
# define CLOSE	0
# define EXIT_SUCCESS	0

typedef	int		t_bool;
typedef	struct	s_door
{
	t_bool state;
}				t_door;
t_bool			open_door(t_door *door);
t_bool			close_door(t_door *door);
t_bool			is_door_open(t_door *door);
t_bool			is_door_close(t_door *door);
#endif


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



#ifndef FT_DOOR_H
# define FT_DOOR_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN	(1)
# define CLOSE	(0)

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct	s_door
{
	int			state;

}				t_door;

#endif



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
