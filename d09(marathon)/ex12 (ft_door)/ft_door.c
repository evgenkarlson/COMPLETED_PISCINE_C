/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_door.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

ft_bool	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
	return (TRUE);
}

ft_bool	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
	return (TRUE);
}

ft_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	door->state = OPEN;
	return (TRUE);
}

ft_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	door->state = CLOSE;
	return (TRUE);
}







/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
}

void	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
}

t_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (door->state = OPEN);
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return (door->state = CLOSE);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
	return (TRUE);
}

t_bool	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
	return (TRUE);
}

t_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (door->state);
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	return (!door->state);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
	return (TRUE);
}

t_bool	close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
	return (TRUE);
}

t_bool	is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	if (door->state == OPEN)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	if (door->state == CLOSE)
		return (TRUE);
	else
		return (FALSE);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
