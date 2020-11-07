#include "ft_rush.h"

int		main(void)
{
	char	rush_input[4001];
	int		number_of_chars;
    int is_correct_input;
    int rows;
    int cols;

	number_of_chars = read(0, rush_input, 4000);
	if (number_of_chars == 0)
		return (0);
	rush_input[number_of_chars] = '\0';

    rows = ft_count_rows(rush_input);
	cols = ft_count_cols(rush_input);

    is_correct_input = ft_is_rush_input_valid(rush_input, rows, cols);
	if (is_correct_input)
		ft_find_rush(rush_input, rows, cols);
	return (0);
}