/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   openfile.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: IHaveNoClueI <ctfx337@gmail.com>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/17 15:05:23 by IHaveNoClueI   #+#    #+#                */
/*   Updated: 2018/10/17 15:05:27 by IHaveNoClueI  ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_openfile()
{
    char openfile;
    char file;

    file = "example.txt";
    openfile = open(file, O_RDONLY);
}
