/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:56:15 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 16:58:48 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

char        *g_progname;
void		ft_putchar(char c);
void		ft_putstr(char *str);
void    	ft_putnbr(int nb);
int         ft_atoi(char *str);
int	    	ft_ctoi(char c);
int		    ft_check_base(char *base);
int	    	ft_atoi_base(char *str, char *base);
void		ft_putstr_non_printable(char *str);
void    	ft_print_memory(void *addr, unsigned int size);

int	    	ft_pow(int nb, int power);

const char	*ft_get_strerr(int errnum);
void		ft_display_custom_error(int eno, char *argv);

int 		ft_size_file(char *argv);
void    	ft_print_name(int i, int argc, char *argv);
void	    ft_display_file(int i, int fd, int argc, char **argv);
void        ft_tail(int argc, char **argv);

#endif
