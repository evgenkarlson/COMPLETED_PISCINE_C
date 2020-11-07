/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/16 11:47:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex01/
**  Файлы для сдачи: ft_boolean.h
**  Разрешенные функции: отсутствуют
**
** ************************************************************************** **
**  
**  
**  - Создайте файл 'ft_boolean.h'. Он скомпилирует и соответствующим образом 
**  выполнит следующие основные функции :
--------------------------------------------------------------------------------

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

--------------------------------------------------------------------------------
**
**  
**  - Эта программа должна отображать :
--------------------------------------------------------------------------------
    I have an even number of arguments.
--------------------------------------------------------------------------------
**
**  
**  - Или :
--------------------------------------------------------------------------------
    I have an odd number of arguments.
--------------------------------------------------------------------------------
**
** 
**  - затем следует разрыв строки, когда это необходимо.
**
**  - «Norminette» должен быть запущен с флагом «-R CheckForbiddenSourceHeader». 
**  «Moulinette» тоже воспользуется этим флагом.
**
**
** ************************************************************************** **
**
**  ВСЁ ПРО typedef             http://www.c-cpp.ru/books/typedef
**                              https://www.youtube.com/watch?v=CTC2Cibv6Ks
**
** ************************************************************************** */
/* ************************************************************************** */


#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define EVEN(nbr)	((nbr % 2) == 0 ? TRUE : FALSE)
# define EVEN_MSG	"I have a pair number of arguments.\n"
# define ODD_MSG	"I have an impair number of arguments.\n"

typedef int	t_bool;
void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);

#endif


/* ************************************************************************** */
/* ************************************************************************** */


#ifndef __FT_BOOLEAN_H
# define __FT_BOOLEAN_H

# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define EVEN(nbr)	((nbr % 2) ? FALSE : TRUE)
# define EVEN_MSG	"I have a pair number of arguments.\n"
# define ODD_MSG	"I have an impair number of arguments.\n"

typedef int	t_bool;
void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);

#endif


/* ************************************************************************** */
/* ************************************************************************** */


# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define EVEN(x)		(!((x) % 2))
# define EVEN_MSG	"I have a pair number of arguments.\n"
# define ODD_MSG	"I have an impair number of arguments.\n"

typedef int	t_bool;
void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);


/* ************************************************************************** */
/* ************************************************************************** */

