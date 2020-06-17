/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ULTIMATE_FIGHT_H
# define FT_ULTIMATE_FIGHT_H
# define PUNCH 0
# define KICK 1
# define KICK1 2
# define KICK2 3
# define KICK3 4
# define KICK4 5
# define KICK5 6
# define KICK6 7
# define KICK7 8
# define KICK8 9
# define KICK9 10
# define KICK10 11
# define KICK11 12
# define HEADBUTT 13
# include "ft_perso.h"

void	ft_putstr(char *str);
void	ft_fight(t_perso *attacker, t_perso *defense, int n);

#endif
