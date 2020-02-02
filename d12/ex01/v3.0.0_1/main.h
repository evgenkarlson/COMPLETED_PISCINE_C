/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 14:27:44 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/17 19:17:56 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

void	jp_putchar(char c);
void	jp_putstr(char *str);
void	jp_puterr(char *name, char *file, int no);
int		jp_cat(char *filename);

#endif
