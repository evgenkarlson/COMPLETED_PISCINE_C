/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 21:14:20 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/21 21:14:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*')
	{
		if (!*s1)
			return (nmatch(s1, s2 + 1));
		else
			return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}
