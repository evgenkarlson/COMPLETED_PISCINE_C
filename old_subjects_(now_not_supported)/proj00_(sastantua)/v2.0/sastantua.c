/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:48:07 by adespond          #+#    #+#             */
/*   Updated: 2015/09/06 20:48:25 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	build_line(int space, int lenght)
{
	int i;

	i = 0;
	while (i++ < space)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < lenght)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	build_line_door(int space, int lenght, int door_size)
{
	int i;
	int y;

	i = 0;
	y = door_size;
	while (i++ < space)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < lenght)
		ft_putchar('*');
	i = 0;
	while (y--)
	{
		if (y == 1 && door_size / 2 == space && door_size > 3)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	while (i++ < lenght)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	build_sastantua(int lenght_total, int size, int start_door)
{
	int current_floor;
	int current_line;
	int lenght;
	int shift;
	int space;

	current_floor = 0;
	lenght = -1;
	shift = 2;
	while (current_floor++ < size)
	{
		current_line = 1;
		while (current_line++ <= (current_floor + 2))
		{
			lenght = lenght + 1;
			space = ((lenght_total / 2) - lenght - 1);
			if (current_floor == size && current_line > (size + 3) - start_door)
				build_line_door(space, lenght - (start_door / 2), start_door);
			else
				build_line(space, (lenght * 2) + 1);
		}
		if (current_floor % 2 && current_floor > 1)
			shift++;
		lenght = shift + lenght;
	}
}

void	sastantua(int size)
{
	int current_floor;
	int current_line;
	int lenght;
	int shift;
	int start_door;

	current_floor = 0;
	lenght = -1;
	shift = 2;
	while (current_floor++ < size)
	{
		current_line = 1;
		while (current_line++ <= (current_floor + 2))
			lenght = lenght + 1;
		if (current_floor % 2 && current_floor > 1)
			shift++;
		lenght = shift + lenght;
	}
	start_door = size - 1;
	if (size % 2)
		start_door++;
	build_sastantua(((lenght - shift) * 2) + 3, size, start_door);
}

int main(void)
{
	sastantua(3);
	return (0);
}
