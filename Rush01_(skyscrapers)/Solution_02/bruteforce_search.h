/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_search.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:30:20 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/10 19:30:23 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRUTEFORCE_SEARCH_H
# define BRUTEFORCE_SEARCH_H

# include "boolean.h"
# include "constraint.h"

t_bool	search_solution(int **grid, int size, t_constr cnstr[4]);

#endif
