/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/22 19:03:14 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/22 19:42:46 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_takes_place(int hour)
{
	int	h;

	h = hour;
	if (hour > 12)
		h = hour % 12;
	if (hour == 0)
		h = 12;

	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour < 11)
		printf("%d.00 A.M. AND %d.00 A.M.\n", h, (h + 1) % 12);
	else if (hour == 11)
		printf("11.00 A.M. AND 12.00 P.M.\n");
	else if (hour == 23)
		printf("11.00 P.M. AND 12.00 A.M.\n");
	else if (hour == 24)
		printf("12.00 A.M. AND 1.00 A.M.\n");
	else
		printf("%d.00 P.M. AND %d.00 P.M.\n", h, (h + 1) % 12);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_takes_place(int hour)
{
	int h1;
	int h2;
	int hs1;
	int hs2;

	h1 = hour;
	h2 = ((hour + 1) == 24 ? 0 : (hour + 1));
	hs1 = 0;
	hs2 = 0;
	if (h1 >= 12)
	{
		h1 = h1 - 12;
		hs1 = 1;
	}
	if (h2 >= 12)
	{
		h2 = h2 - 12;
		hs2 = 1;
	}
	h1 = (h1 == 0 ? 12 : h1);
	h2 = (h2 == 0 ? 12 : h2);
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s. AND %d.00 %s.\n", h1,
			(hs1 == 0 ? "A.M" : "P.M"), h2, (hs2 == 0 ? "A.M" : "P.M"));
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_takes_place(int hour)
{
	char	ampm;
	int		late;

	if (hour == 24)
		hour -= 24;
	late = hour > 11 ? 1 : 0;
	ampm = late ? 80 : 65;
	printf("%s", "THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour > 12)
		printf("%d", hour - 12);
	else
		printf("%d", (hour == 0) ? hour + 12 : hour);
	printf(".00 %cM AND ", ampm);
	if (hour == 11)
		ampm = 80;
	else if (hour == 23)
		ampm = 65;
	if (late)
		printf("%d", hour - 11);
	else
		printf("%d", hour + 1);
	printf(".00 %cM\n", ampm);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_takes_place(int hour)
{
	if (hour >= 0 && hour <= 24)
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		if (hour == 0 || hour == 24)
			printf("12.00 A.M AND 1.00 A.M.\n");
		if (hour == 11)
			printf("11.00 A.M. AND 12.00 P.M.\n");
		else if (hour == 12)
			printf("12.00 P.M. AND 1.00 P.M.\n");
		else if (hour == 23)
			printf("11.00 P.M. AND 12.00 A.M.\n");
		else if (hour >= 1 && hour <= 10)
			printf("%d.00 A.M. AND %d.00 A.M.\n", (hour), (hour + 1));
		else if (hour >= 13 && hour <= 22)
			printf("%d.00 P.M. AND %d.00 P.M.\n", (hour - 12), (hour - 11));
	}
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
