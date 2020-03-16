/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:30:17 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:30:18 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H

# define OPERATOR_H

typedef struct	s_opp
{
	char *literal;
	void *f;
}				t_opp;

void			eval_ops(t_list *n, int hp);

#endif
