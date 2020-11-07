/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 00:30:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

char        *g_progname;
void        ft_stdin(void);
void		ft_putchar(char c);
void		ft_putstr(char *str);
const char	*ft_get_strerr(int errnum);
void		ft_display_custom_error(int eno, char *argv);
void	    ft_display_file(char *argv);
void        ft_cat(int argc, char **argv);

#endif
