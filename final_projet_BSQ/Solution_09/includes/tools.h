/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:49:29 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 20:21:34 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

char	*ft_strcat(char *dest, char *src);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_map_error();

#endif
