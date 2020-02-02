/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 14:58:07 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/28 14:58:21 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_list.h"

t_list	*add_link(t_list *list, void *data)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = list;
	}
	return (tmp);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 2;
	if (ac == 1)
		return (NULL);
	list = ft_create_elem(av[1]);
	while (i < ac)
	{
		list = add_link(list, av[i]);
		i++;
	}
	return (list);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	t_list	*list;
	int		i;

	i = 1;
	list = ft_create_elem(av[0]);
	tmp = list;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
	return (list);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	list = NULL;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = tmp;
		tmp = list;
		i += 1;
	}
	return (list);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
