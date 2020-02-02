/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:09:22 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/14 12:45:47 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H
# define PUNCH "punch"
# define KICK "kick"
# define HEADBUTT "headbutt"
# include "ft_perso.h"

void	ft_fight(t_perso *attacker, t_perso *defense, char *attack);

#endif
