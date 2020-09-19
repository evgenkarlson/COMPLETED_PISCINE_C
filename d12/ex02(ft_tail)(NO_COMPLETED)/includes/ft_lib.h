/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define BUF_SIZE 1024

char        *g_progname;
void		ft_putchar(char c);
void		ft_putstr(char *str);
int         ft_atoi(char *str);

const char	*ft_get_strerr(int errnum);
void		ft_display_custom_error(int eno, char *argv);

int 		ft_size_file(char *argv);
void    	ft_print_name(int i, int argc, char *argv);
void	    ft_display_file(int i, int fd, int argc, char **argv);
void        ft_tail(int argc, char **argv);

#endif
