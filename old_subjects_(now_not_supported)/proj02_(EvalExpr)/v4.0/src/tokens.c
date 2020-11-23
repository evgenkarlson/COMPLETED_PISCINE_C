/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:27:23 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:27:24 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "str_utils.h"

char	*skip_par_block(char *str)
{
	int n;

	n = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str == '(')
			n++;
		if (*str == ')')
			n--;
		str++;
		if (!n)
			break ;
	}
	return (str);
}

char	*skip_operand_token(char *str)
{
	str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*skip_operator_token(char *str)
{
	return (str + 1);
}

char	*get_token(char **str, int *even)
{
	char *ret;
	char *ptr;

	skip_spaces(str);
	ptr = *str;
	if (!ptr)
		return (0);
	ptr = *str;
	if (*ptr == '(' || (*ptr == '-' && *(ptr + 1) == '('))
		ptr = skip_par_block(ptr);
	else if (*even)
		ptr = skip_operator_token(ptr);
	else
		ptr = skip_operand_token(ptr);
	ret = malloc(sizeof(char) * (ptr - *str + 1));
	ft_strlcpy(ret, *str, (ptr - *str + 1));
	*str = ptr;
	*even = !*even;
	return (ret);
}
