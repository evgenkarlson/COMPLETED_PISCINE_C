/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:12:14 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 12:12:14 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

int		ft_str_join_get_final_length(char **strings, int size, int sep_length);
char	*ft_str_join(int size, char **strs, char *sep);

int		ft_str_length(char *str);

char	*ft_str_duplicate(char *src);
char	*ft_str_n_duplicate(char *src, int n);

char	*ft_str_copy(char *dest, char *src);
char	*ft_str_n_copy(char *dest, char *src, int n);

void	ft_str_write_to(int fd, char *str);
void	ft_str_write(char *str);

#endif
