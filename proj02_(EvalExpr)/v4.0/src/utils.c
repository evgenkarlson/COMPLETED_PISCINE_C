/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:28:20 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:28:21 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	skip_spaces(char **str)
{
	while (**str && is_space(**str))
		(*str)++;
}

void	skip_non_spaces(char **str)
{
	while (**str && !is_space(**str))
		(*str)++;
}

int		ft_atoi(char *str)
{
	int v;
	int is_positive;

	v = 0;
	is_positive = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		v *= 10;
		v -= *str - '0';
		str++;
	}
	v *= -(is_positive + !is_positive);
	return (v);
}
