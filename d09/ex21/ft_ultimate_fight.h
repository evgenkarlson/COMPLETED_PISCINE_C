/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:09:22 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/14 16:32:36 by lkinzel          ###   ########.fr       */
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

void	ft_fight(t_perso *attacker, t_perso *defense, int n);

#endif
