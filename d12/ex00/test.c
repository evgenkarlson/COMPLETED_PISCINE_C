#include <unistd.h>
#include <fcntl.h>

#define NONE	{ft_putstr("No such file or directory.\n"); return ;}
#define DIR		{ft_putstr(argv[1]);ft_putstr(": Is a directory.\n");return;}
#define BUFF_SIZE	4096


#ifndef FT_LIB_H
# define FT_LIB_H

void	ft_putstr(char *str);
void	ft_display_stdin(int file);
void	ft_display_file(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

#endif

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_display_file(int argc, char **argv)
{
	int	file;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
			DIR;
		file = open(argv[1], O_WRONLY);
		ft_putchar((file % 10) + '0');
		ft_putchar('\n');
		if (file == -1)
			NONE;
//		ft_display_stdin(file);
		close(file);
	}
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc < 2)
		ft_putstr("File name missing.\n");
}	

void	ft_display_stdin(int file)
{
	char	buffer[BUFF_SIZE + 1];

	while (read(file, buffer, BUFF_SIZE))
		ft_putstr(buffer);
}

int		main(int argc, char **argv)
{
	ft_display_file(argc, argv);
	return (0);
}