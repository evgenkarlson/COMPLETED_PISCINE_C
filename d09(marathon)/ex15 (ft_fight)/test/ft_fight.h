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


#ifndef __FT_FIGHT_H
# define __FT_FIGHT_H
# define KICK 'k'
# define PUNCH 'p'
# define HEADBUTT 'h'
# include <unistd.h>

void	ft_fight(t_perso *attacker, t_perso *defense, char attack);

#endif

