/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 22:19:06 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/20 23:19:36 by rbufnoir         ###   ########.fr       */
/*   Updated: 2014/07/20 23:20:23 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		jp_colle00(char *str, char *cha)
{
	if (cha[0] == 'o' && cha[1] == '-' && cha[2] == 'o'
		&& cha[3] == '|' && cha[4] == 'o'  && cha[5] == 'o')
		return (1);
	return (0);
}

int		jp_colle01(char *str, char *cha)
{
	if (cha[0] == '/' && cha[1] == '*' && cha[2] == '\\'
		&& cha[3] == '*' && cha[4] == '\\' && cha[5] == '/')
		return (1);
	return (0);
}

int		jp_colle02(char *str, char *cha)
{
	if (cha[0] == 'A' && cha[1] == 'B' && cha[2] == 'A'
		&& cha[3] == 'B' && cha[4] == 'C' && cha[5] == 'C')
		return (1);
	return (0);
}

int		jp_colle03(char *str, char *cha)
{
	if (cha[0] == 'A' && cha[1] == 'B' && cha[2] == 'C'
		&& cha[3] == 'B' && cha[4] == 'A' && cha[5] == 'C')
		return (1);
	return (0);
}

int		jp_colle04(char *str, char *cha)
{
	if (cha[0] == 'A' && cha[1] == 'B' && cha[2] == 'C'
		&& cha[3] == 'B' && cha[4] == 'C' && cha[5] == 'A')
		return (1);
	return (0);
}
