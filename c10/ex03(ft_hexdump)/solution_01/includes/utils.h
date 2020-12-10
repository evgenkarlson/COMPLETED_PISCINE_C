/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:09 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:23:44 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFSIZE (256)
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_concat_params(int argc, char **argv);
char	*get_file(char *filename);
int		ft_strlen(char *str);
int		file_exists(char *filename);
int		get_option(int argc, char **argv, int *index);
int		ft_memcmp(unsigned char *s1, unsigned char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
void	print(char *str);
void	print_error_message(int errcode, char *str);
void	concat_strings(char **dest, char *src, int amount);
void	*ft_print_memory(void *addr, unsigned int size, int option);
void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr, int option);
void	print_line(unsigned char *curr, unsigned char *end, \
					unsigned char *addr, int option);
void	read_input(int hex_display);
void	read_argument_files(int argc, char **argv, int i, int hex_display);
void	read_single_file(char **argv, int i, int hex_display);
void	read_file(char *file, int hex_display);
void	print_hex(unsigned int value, int length);
void	print_asterisk(int *asterisk);

#endif
