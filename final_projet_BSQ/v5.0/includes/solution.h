/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:57:54 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/08/19 18:59:14 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

static void		actualize_sol(t_solution *sol, t_solution *intent,
					const t_grid *grid);
static t_bool	fits(const t_solution *sol, const t_grid *grid);
static t_bool	fits_succ(const t_solution *intent, const t_grid *grid);
static t_bool	dont_fit_basic(const t_solution *intent, const t_grid *grid);

#endif
