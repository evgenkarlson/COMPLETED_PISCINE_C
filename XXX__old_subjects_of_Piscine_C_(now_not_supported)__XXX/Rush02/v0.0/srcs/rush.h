/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 19:29:40 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 23:16:51 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 2048

typedef struct		s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

void				ft_putstr(char *c);
void				ft_putnbr(int num);
void				ft_putchar(char c);
int					num_sides(int x, int y, int wid, int len);

int					r00c(int wid, int len, char **str);
int					r01c(int wid, int len, char **str);
int					r02c(int wid, int len, char **str);
int					r03c(int wid, int len, char **str);
int					r04c(int wid, int len, char **str);

char				*ft_import_stdin(void);
t_list				*ft_create_list(char c);
void				ft_push_list(t_list **first, char c);
char				*ft_concat_list(t_list *list, int len);

int					get_x(char *str);
int					get_y(char *str);
char				**make_space(char **grid, int x, int y);
void				copy_grid(char **grid, char *str, int x, int y);
void				print_rush(char *str, int *xy, int index, int num);

#endif
