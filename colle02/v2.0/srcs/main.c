/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 14:22:37 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/20 23:13:50 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*jp_check(char *str, char *cha)
{
	int		tab[4];

	tab[0] = 0;
	tab[1] = -1;
	tab[2] = 0;
	tab[3] = 0;
	while (str[++tab[1]] != '\0')
	{
		if (str[tab[1]] == '\n')
		{
			if (tab[2] == 0)
				tab[2] = tab[0];
			tab[3]++;
		}
		if (tab[2] == 0)
			tab[0]++;
	}
	cha[0] = str[0];
	cha[1] = str[1];
	cha[2] = str[tab[2] - 1];
	cha[3] = str[tab[2] + 1];
	cha[5] = str[(tab[2] * tab[3]) + (tab[3] - 1) - 1];
	cha[4] = str[(tab[2] * (tab[3] - 1)) + (tab[3] - 1)];
	return (cha);
}

int		*jp_get_size(char *str)
{
	int		i;
	int		j;
	int		*size;

	if ((size = (int *)malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	while (str[++j] != '\0')
	{
		if (str[j] == '\n')
		{
			if (size[1] == 0)
				size[1] = i;
			size[0]++;
		}
		if (size[1] == 0)
			i++;
	}
	return (size);
}

void	jp_print_result(char *str)
{
	int		*ret[5];
	int		*size;
	char	*cha;

	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
	ret[3] = 0;
	ret[4] = 0;
	size = jp_get_size(str);
	if ((cha = (char *)malloc(sizeof(char) * 6)) != NULL)
	{
		cha = jp_check(str, cha);
		if ((ret[0] = jp_colle00(str, cha)) == 1)
			jp_show(0, size[1], size[0], jp_test_tab(ret));
		if ((ret[1] = jp_colle01(str, cha)) == 1)
			jp_show(1, size[1], size[0], jp_test_tab(ret));
		if ((ret[2] = jp_colle02(str, cha)) == 1)
			jp_show(2, size[1], size[0], jp_test_tab(ret));
		if ((ret[3] = jp_colle03(str, cha)) == 1)
			jp_show(3, size[1], size[0], jp_test_tab(ret));
		if ((ret[4] = jp_colle04(str, cha)) == 1)
			jp_show(4, size[1], size[0], jp_test_tab(ret));
	}
}

int		main(void)
{
	t_list	*list;
	int		pos;
	int		len;
	char	buff[129];
	char	*str;
	char	*cha;

	while ((pos = read(0, buff, 128)))
	{
		buff[pos] = '\0';
		len += pos + 1;
		if (list == NULL)
			list = jp_create_elem(buff);
		else
			jp_list_push_back(&list, buff);
	}
	str = (char *)malloc(sizeof(char) * len);
	while (list != NULL)
	{
		jp_strcat(str, list->str);
		list = list->next;
	}
	jp_print_result(str);
	return (0);
}
