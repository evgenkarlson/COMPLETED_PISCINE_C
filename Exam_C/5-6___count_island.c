/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-6___count_island.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/23 01:52:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name  : count_island
Expected files   : *.c, *.h
Allowed functions: open, close, read, write, malloc, free
--------------------------------------------------------------------------------

Напишите программу, которая принимает файл, содержащий строки одинаковой длины. 
Эти строки содержат символы, которые либо являются '.' или 'X'. Все эти линии 
вместе образуют прямоугольники из символа '.' содержащие «острова» 'X'.

Максимальный размер строки - 1024 символа, включая завершающую новую строку.

Столбец, если он сформирован из набора символов в файле, которые отделены от 
начала своих соответствующих строк одинаковым количеством символов.

Говорят, что два символа соприкасаются друг с другом, если они смежные и 
находятся в одной строке или в смежных строках и в одном столбце.

«Остров» из «X» означает набор «X», соприкасающихся друг с другом.

Программа должна пройти через файл и отобразить его после замены всех «X» 
числом, соответствующим положению их острова в файле, начиная с начала файла.

Результат может быть только один.

Если файл пуст, или есть ошибка (например, некогерентный ввод), или параметры 
не переданы, программа должна отображать новую строку.

Файл содержит не более 10 островов.

Вы найдете примеры в тематическом каталоге.

Примеры:

$>cat johndoe
.................XXXXXXXX..........................................
....................XXXXXXXXX.......XXXXXXXX.......................
.................XXXXXXXX..............XXX...XXXXX.................
.....................XXXXXX.....X...XXXXXXXXXXX....................
................................X..................................
......XXXXXXXXXXXXX.............X..................................
..................X.............XXXXXXXXX..........................
..................X.........XXXXXXXXXXXX...........................
..................X................................................
XX.............................................................XXXX
XX..................XXXXXXXXXXXXX.................................X
...................................................................
.................................................................X.
.....................XXXXX.......................................XX
$>
$>./count_island johndoe
.................00000000..........................................
....................000000000.......11111111.......................
.................00000000..............111...11111.................
.....................000000.....2...11111111111....................
................................2..................................
......3333333333333.............2..................................
..................3.............222222222..........................
..................3.........222222222222...........................
..................3................................................
44.............................................................5555
44..................6666666666666.................................5
...................................................................
.................................................................7.
.....................88888.......................................77
$>

$>cat who-s-there
...................................................................
...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......
...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......
...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............
...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............
...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........
...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........
...XX......XX..XX.......XX..XX.XX..........XX......XX..............
...XX......XX..XX.......XX..XX...X.........XX......XX..............
...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......
...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...
...................................................................
$>
$>./count_island who-s-there
...................................................................
...0........0.....11111......2222222...3333333333..4444444444......
...00......00....11...11....22.....22.....3333.....4444444444......
...0000..0000...11.....11...22.....22......33......44..............
...00.0000.00...11.....11...22.....22......33......44..............
...00...0..00...11.....11...22222222.......33......44444...........
...00......00...111111111...2222...........33......44444...........
...00......00..11.......11..22.22..........33......44..............
...00......00..11.......11..22...5.........33......44..............
...00......00..11.......11..22....6......333333....4444444444......
...00......00.11.........11.22.....77..3333333333..4444444444..8...
...................................................................
$>

$>cat -e void
$>./count_island void | cat -e
$
$>


** ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#include <fcntl.h>

void	flood_fill(char *map, int i, char c, int width, int total_b)
{
	map[i] = c;
	if (i > width && map[i - width] == 'X')
		flood_fill(map, i - width, c, width, total_b);
	if (i + width < total_b - 1 && map[i + width] == 'X')
		flood_fill(map, i + width, c, width, total_b);
	if (i - 1 >= 0 && map[i - 1] == 'X')
		flood_fill(map, i - 1, c, width, total_b);
	if (i + 1 < total_b - 1 && map[i + 1] == 'X')
		flood_fill(map, i + 1, c, width, total_b);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char map[102400] = {0};
	int fd = open(av[1], O_RDONLY);
	int total_b = read(fd, map, 102400);

	if (total_b <= 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	int width = 1;
	int i = 0;
	while (map[i] != '\n')
	{
	 	i++;
		width++;
	}
	int height = 0;
	for (int i = 0; i < total_b; i++)
	{
		if (map[i] != 'X' && map[i] != '.' && map[i] != '\n' && map[i] != '\0')
		{
			write(1, "\n", 1);
        	return (0);
		}
		if (map[i] == '\n')
			height++;
	}

	if (height * width != total_b)
	{
		write(1, "\n", 1);
		return (0);
	}
	char replacer = '0';
	for (int i = 0; i < total_b; i++)
	{
		
		if (map[i] == 'X') 
		{
			flood_fill(map, i, replacer, width, total_b);
			replacer++;
		}
	}
	if (replacer > ':')
	{
		write(1, "\n", 1);
        return (0);
	}
	write(1, map, total_b);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	count_island(char **i, int x, int y, char c);
void	sefsrg(char **i);
char	**cread(int fd);

void		count_island(char **i, int x, int y, char c)
{
	if (y < 0 || x < 0 || !i[y] || !i[y][x] || i[y][x] != 'X')
		return ;
	i[y][x] = c;
	count_island(i, x + 1, y, c);
	count_island(i, x - 1, y, c);
	count_island(i, x, y + 1, c);
	count_island(i, x, y - 1, c);
}

void		sefsrg(char **i)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	c = '0';
	while (i[y])
	{
		x = 0;
		while (i[y][x])
		{
			if (i[y][x] == 'X')
				count_island(i, x, y, c++);
			write(1, i[y] + x, 1);
			x++;
		}
		y++;
		if (x > 0)
			write(1, "\n", 1);
	}
}

int			read_first_line(int fd, char **r)
{
	int		i = 0;

	r[0] = malloc(sizeof(char) * 1300);
	while (read(fd, r[0] + i, 1) > 0)
	{
		if (r[0][i] == '\n')
		{
			r[0][i] = 0;
			return (i);
		}
		else if (r[0][i] != '.' && r[0][i] != 'X')
			return (-1);
		i++;
	}
	return (-1);
}

int			read_one_line(int fd, int len, char **r)
{
	int		readed;

	*r = malloc(sizeof(char) * (len + 10));
	readed = read(fd, *r, len + 1);
	if (readed == -1)
		return (-1);
	if (readed == 0)
		return (0);
	if (readed == 1 && **r == '\n')
	{
		**r = 0;
		return (0);
	}
	if (readed < len)
		return (-1);
	if (r[0][len] != '\n')
		return (-1);
	r[0][len] = 0;
	readed -= 2;
	while (readed >= 0)
	{
		if (r[0][readed] != 'X' && r[0][readed] != '.')
			return (-1);
		readed--;
	}
	return (1);
}

char		**cread(int fd)
{
	char	**result;
	int		i;
	int		linelen;
	int		ret;

	result = malloc(sizeof(char *) * 100000);
	i = 0;
	linelen = read_first_line(fd, result);
	if (linelen < 1)
		return (0);
	i++;
	while (1)
	{
		ret = read_one_line(fd, linelen, result + i);
		if (ret == -1)
			return (0);
		if (ret == 0)
			break ;
		i++;
	}
	return (result);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**a;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd != -1)
		{
			a = cread(fd);
			close(fd);
			if (a != 0)
			{
				sefsrg(a);
				return (0);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}



/* ************************************************************************** */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define LIM 100000

int errorCheck(char buf[LIM], int size, int width, int height) {

	if (size / height != width) {
		write(1, "\n", 1);
		return 0;
	}

	for (int i = 0; i < size; i++) {
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
			return 0;
	}
	
	return 1;
}

void floodFill(char buf[LIM], int size, int width, int height, int i, char replacer) {

	buf[i] = replacer;

	if ((i > width) && (buf[i - width] == 'X'))
		floodFill(buf, size, width, height, i - width, replacer);

	if ((i < size - width - 1) && buf[i + width] == 'X')
		floodFill(buf, size, width, height, i + width, replacer);

	if (i && (i % width > 0) && buf[i - 1] == 'X')
		floodFill(buf, size, width, height, i - 1, replacer);

	if (i && (i % width < width - 1) && buf[i + 1] == 'X')
		floodFill(buf, size, width, height, i + 1, replacer);
}

void countIsland(char* file) {
	
	char buf[LIM] = {0};
	int fd = open(file, O_RDONLY);

	int size = read(fd, buf, LIM);
	if (size < 0) {
		write(1, "\n", 1);
		return;
	}

	int width = 1;
	for (int i = 0; buf[i] != '\n'; i++)
		width++;

	int height = size / width;

	if (!errorCheck(buf, size, width, height))
		return;

	char replacer = '0';
	for (int i = 0; i < size; i++) {
		if (buf[i] == 'X') {
			floodFill(buf, size, width, height, i, replacer);
			replacer++;
		}
	}
	write(1, buf, size);
}

int main(int ac, char* av[]) {
	if (ac == 2)
		countIsland(av[1]);
	return 0;
}