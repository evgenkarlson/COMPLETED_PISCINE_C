
#include "ft_rush.h"

void	ft_print_rush(int rows, int cols, int n_matches, char rush_number)
{
	if (n_matches > 0)
		write(1, " || ", 4);
	write(1, "[rush-0", 7);
	write(1, &rush_number, 1);
	write(1, "] [", 3);
	ft_putnbr(cols);
	write(1, "] [", 3);
	ft_putnbr(rows);
	write(1, "]", 1);
}

void	ft_find_rush(char *input, int rows, int cols)
{
	int n_matches;

	n_matches = 0;

	if (ft_strings_equal(input, ft_rush00(cols, rows)))
		ft_print_rush(rows, cols, n_matches++, '0');
	if (ft_strings_equal(input, ft_rush01(cols, rows)))
		ft_print_rush(rows, cols, n_matches++, '1');
	if (ft_strings_equal(input, ft_rush02(cols, rows)))
		ft_print_rush(rows, cols, n_matches++, '2');
	if (ft_strings_equal(input, ft_rush03(cols, rows)))
		ft_print_rush(rows, cols, n_matches++, '3');
	if (ft_strings_equal(input, ft_rush04(cols, rows)))
		ft_print_rush(rows, cols, n_matches++, '4');
	if (n_matches == 0)
		ft_print_error(6);
	write(1, "\n", 1);
}