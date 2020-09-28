/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:16:41 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************   


• Create a ft_boolean.h file. It’ll compile and run the following main appropriately
• Создать файл ft_boolean.h. Он скомпилирует и запустит следующее основное:


   **************************************************************************    


#include "ft_boolean.h"

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

t_bool  ft_is_even(int nbr)
{
    return ((EVEN(nbr)) ? TRUE : FALSE);
}

int     main(int argc, char **argv)
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);
    return (SUCCESS);
}


   **************************************************************************  


• Эта программа должна отображать:

        I have an even number of arguments.

• или:

        I have an odd number of arguments.


• с последующим разрывом строки, когда это необходимо.


   **************************************************************************  


    ВСЁ ПРО typedef             http://www.c-cpp.ru/books/typedef
                                https://www.youtube.com/watch?v=CTC2Cibv6Ks


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

#define	TRUE		1
#define	FALSE		0
#define	SUCCESS		0
#define	EVEN_MSG	"I have an even number of arguments.\n"
#define	ODD_MSG		"I have an odd number of arguments.\n"
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
