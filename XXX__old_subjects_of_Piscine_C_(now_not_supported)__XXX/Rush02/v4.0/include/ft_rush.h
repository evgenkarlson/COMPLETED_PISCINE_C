#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>

void	ft_find_rush(char *input, int rows, int cols);
int		ft_is_rush_input_valid(char *input, int rows, int cols);
int		ft_count_rows(char *str);
int		ft_count_cols(char *str);
int		ft_strings_equal(char *str1, char *str2);
void    ft_print_error(int n);
char	*ft_rush00(int x, int y);
char	*ft_rush01(int x, int y);
char	*ft_rush02(int x, int y);
char	*ft_rush03(int x, int y);
char	*ft_rush04(int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putrush(char rush, int rows, int cols, int first_match);

#endif