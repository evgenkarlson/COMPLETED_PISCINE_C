/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 16:08:16 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/23 19:33:24 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*jp_ltos(int len, t_list *list)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	while (list != NULL)
	{
		jp_strcat(str, list->str);
		list = list->next;
	}
	return (str);
}

char	*jp_read_standard(void)
{
	t_list	*list;
	int		pos;
	int		len;
	char	buff[129];

	len = 0;
	while ((pos = read(0, buff, 128)))
	{
		buff[pos] = '\0';
		len += pos + 1;
		if (list == NULL)
			list = jp_create_elem(buff);
		else
			jp_list_push_back(&list, buff);
	}
	return (jp_ltos(len, list));
}

char	*jp_openfile(char *filename)
{
	t_list	*list;
	int		fh;
	char	buff[4097];
	int		pos;
	int		len;

	len = 0;
	if ((fh = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while ((pos = read(fh, &buff, 4096)))
	{
		buff[pos] = '\0';
		jp_putstr(buff);
		len += pos + 1;
		if (list == NULL)
			list = jp_create_elem(buff);
		else
			jp_list_push_back(&list, buff);
	}
	close(fh);
	return (jp_ltos(len, list));
}

void	jp_check(char *str)
{
	if (str == NULL || *str == '\0')
		jp_puterr("map error\n");
	if (bsq(str) == 0)
		jp_puterr("map error\n");
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		while (*++argv != '\0')
		{
			jp_check(jp_openfile(*argv));
		}
	else
		jp_check(jp_read_standard());
	return (0);
}
