#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE	4096


#ifndef FT_LIB_H
# define FT_LIB_H

void	ft_putstr(char *str);
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


void	ft_display_stdin(int fd)
{
	char	buffer[BUFF_SIZE + 1];

	buffer[BUFF_SIZE] = '\0';
	while (read(fd, buffer, BUFF_SIZE))
		ft_putstr(buffer);
	ft_putchar('\n');
}
/*
void	ft_display_stdin(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		nb_char;

	nb_char = 1;
	while (nb_char)
	{
		nb_char = read(fd, buffer, BUFF_SIZE);
		write(1, buffer, nb_char);
	}
	ft_putchar('\n');
}
*/
void	ft_display_file(int argc, char **argv)
{
	int		file;

	if (argc > 1)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "/") == 0 ||
			ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0 ||
			ft_strcmp(argv[1], "../") == 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": Is a directory.\n");
			return;
		};
		if ((file = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("No such file or directory.\n");
			return ;
		}
		ft_display_stdin(file);
		close(file);
	}
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc < 2)
		ft_putstr("File name missing.\n");
}



int		main(int argc, char **argv)
{
	ft_display_file(argc, argv);
	return (0);
}