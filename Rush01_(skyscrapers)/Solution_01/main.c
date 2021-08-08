/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:22:06 by cromalde          #+#    #+#             */
/*   Updated: 2021/08/08 21:12:54 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		initboard(int *input);

int		checksintax(char *input)
{
	int i;
	int err;

	i = 0;
	err = 0;
	while (input[i])
	{
		if (input[i] == '4')
			err++;
		i++;
	}
	if (err > 2)
		return (0);
	i = 0;
	err = 0;
	while (input[i])
	{
		if (input[i] == '1')
			err++;
		i++;
	}
	if (err != 4)
		return (0);
	return (1);
}

int		checkinput(char *arg, int *input)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (checksintax(arg) == 1)
	{
		while (arg[i])
		{
			if ((arg[i] >= '1' && arg[i] <= '4') && ((arg[i + 1] == ' ')
					|| ((arg[i + 1] == 0) && (arg[i - 1] == ' '))))
			{
				input[out] = (arg[i] - '0');
				out++;
				i++;
			}
			if ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
				i++;
			else
				return (out);
		}
		input[out] = '\0';
		return (out);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int input[16];

	if (argc == 2)
	{
		if (checkinput(argv[1], input) == 16)
			initboard(input);
		else
			write(1, "\nERROR\n\n", 8);
	}
	else
		write(1, "\nERR - Inserire UN solo argomento\n\n", 35);
	return (0);
}
/*
>   gcc -Werror -Wall -Wextra ./main.c ./beforestart.c ./checkboard.c ./do_your_job.c ./print.c -o ./main.out -I . && chmod +x ./main.out && ./main.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
>
>
>         "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
>	
>
>       UP        RIGHT       LEFT        DOWN
>    "4 3 2 1    1 2 2 2    4 3 2 1     1 2 2 2"
>
>
>                     4 3 2 1
>                    ---------
>                  4| 1 2 3 4 |1
>                  3| 2 3 4 1 |2
>                  2| 3 4 1 2 |2
>                  1| 4 1 2 3 |2
>                    ---------
>                     1 2 2 2
>
>
>  Каждая цифра внутри квадрата обозначает высоту здания(от 1 до 4).
>
>  Каждая цифра снаружи квадрата отображает количество зданий,
>  видимых на линии со стороны каждой цифры-подсказки
*/