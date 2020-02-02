/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <tde-roqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:25:09 by tde-roqu          #+#    #+#             */
/*   Updated: 2015/09/13 10:28:57 by mfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	if (check_grille(argv, argc))
	{
		if (sudoku(argv, 9))
			affichage(argv);
		else
		{
			ft_putstr("Erreur");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Erreur");
		ft_putchar('\n');
	}
	return (0);
}
