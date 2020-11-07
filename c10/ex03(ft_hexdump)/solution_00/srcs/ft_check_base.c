/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/07 23:32:50 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		z = i + 1;
		while (base[z])
		{
			if (base[i] >= base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (i);
}