/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *name, char *file, int num);
int		ft_cat(char *filename);

#endif
