/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define	TRUE		1
#define	FALSE		0
#define	SUCCESS		0
#define	EVEN_MSG	"J'ai un nombre pair d'arguments.\n"
#define	ODD_MSG		"J'ai un nombre impair d'arguments.\n"
#define	EVEN(x)		(!((x) % 2))

typedef int t_bool;




/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */



#ifndef		FT_BOOLEAN_H
# define	FT_BOOLEAN_H

# include <unistd.h>

typedef	int	t_bool;

# define	TRUE	1
# define	FALSE	0
# define	EVEN(x)	((x % 2) == 0 ? TRUE : FALSE)
# define	SUCCESS	0

# define	EVEN_MSG	"I have a pair number of arguments.\n"
# define	ODD_MSG		"I have an impair number of arguments.\n"

void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);

#endif




/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */



#ifndef FT_H
# define FT_H

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);

#endif


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


#ifndef __FT_BOOLEAN_H
# define __FT_BOOLEAN_H

# include <unistd.h>

# define SUCCESS 0
# define EVEN(nbr) (nbr % 2 ? FALSE : TRUE)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have a pair number of arguments.\n"
# define ODD_MSG "I have an impair number of arguments.\n"

typedef int	t_bool;
#endif


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */



#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <stdlib.h>

# define EVEN_MSG 	"I have an even number of arguments.\n"
# define ODD_MSG	"I have an odd number of arguments.\n"
# define SUCCESS	0

# define TRUE		1
# define FALSE		0

# define EVEN(x)	(!((x) % 2))

typedef int			t_bool;

#endif


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
