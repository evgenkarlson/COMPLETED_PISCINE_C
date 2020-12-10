/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 22:31:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/07 22:31:17 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_sast_floor	t_sast_floor;

struct	s_sast_floor
{
	int		idx;
	int		height;
	int		top_width;
	char	last;
};

void	ft_putchar(char c);

void	sast_floor_printc(t_sast_floor *floor, int line, int col, int star)
{
	int door_len;
	int door_pos;

	door_len = floor->idx % 2 == 0 ? floor->idx - 1 : floor->idx;
	door_pos = (star - 1) / 2 - ((floor->height - 1) / 2);
	if (floor->last && floor->height - line <= door_len
		&& col > door_pos && col <= door_pos + door_len)
	{
		if (floor->idx > 4 && floor->height - line == (door_len - 1) / 2 + 1
			&& col == door_pos + door_len - 1)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	else
		ft_putchar('*');
}

void	sast_floor_println(t_sast_floor *floor, int lead, int line, int star)
{
	int to_lead;
	int col;

	to_lead = -1;
	col = -1;
	while (++to_lead < lead)
		ft_putchar(' ');
	ft_putchar('/');
	while (++col < star)
		sast_floor_printc(floor, line, col, star);
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sast_floor_print(t_sast_floor *floor, int base_width)
{
	int star;
	int leading;
	int line;

	star = floor->top_width - 2;
	leading = (base_width - 1) / 2 - ((floor->top_width - 1) / 2);
	line = -1;
	while (++line < floor->height)
	{
		sast_floor_println(floor, leading, line, star);
		star += 2;
		--leading;
	}
}

void	sastantua(int size)
{
	int				floor_top_width;
	int				floor_width;
	int				pas;
	int				i;
	t_sast_floor	floors[size];

	floor_top_width = 3;
	pas = 10;
	floor_width = 0;
	i = 1;
	while (i <= size)
	{
		floors[i - 1] = (t_sast_floor) {
			i, 3 + i - 1, floor_top_width,
			i == size
		};
		floor_width = floor_top_width + (i + 1) * 2;
		floor_top_width += pas;
		pas += ++i % 2 == 0 ? 2 : 4;
	}
	i = -1;
	while (++i < size)
		sast_floor_print(floors + i, floor_width);
}
