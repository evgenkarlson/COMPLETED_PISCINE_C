/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:56:15 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 23:28:51 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H


# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

char        *g_progname;
void		ft_putchar(char c);
void		ft_putstr(char *str);
int		    ft_check_base(char *base);

int	    	ft_pow(int nb, int power);

const char	*ft_get_strerr(int errnum);
void		ft_display_custom_error(int eno, char *argv);

void     	ft_print_address(int nbr, char *hex);
void	    ft_print_hex(int i, unsigned int size, unsigned char *p, char *hex);
void    	ft_print_char(int i, unsigned int size, unsigned char *p);
int 		ft_check_file(char *argv);
void    	ft_hexdump(int argc, char **argv);

#endif
