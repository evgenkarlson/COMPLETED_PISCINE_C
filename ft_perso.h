/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_AUSTIN_POWERS "Save Austin Powers"
# include <string.h>

typedef struct	s_persos {
	char	*name;
	float	life;
	int		age;
	char	*profession;
}				t_perso;

#endif


