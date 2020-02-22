/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:17:56 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 18:26:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.
Напишите программу, которая принимает строку и меняет регистр всех ее букв.
Другие персонажи остаются без изменений.

You must display the result followed by a '\n'.
Вы должны отобразить результат, за которым следует '\ n'.

If the number of arguments is not 1, the program displays '\n'.
Если количество аргументов не равно 1, программа отображает '\ n'.




Examples :
Примеры :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$



   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])/* здесь принимаем количество строк в массиве и сам массив со строками */
{	
	int i;							/* ля начала обьявим переменную для счетчика */

	if (argc != 2)					/* Если кроме имени программы в аргументах ничего нет */
	{
		write(1,'\n',1);			/* то печатаем символ переноса строки */
		return (0);					/* и завершаем программу */
	}
	i = 0;							/* Инициализруем счетчик нулем чтобы начать с нулевой ячейки */
	while (argv[1][i])				/* Запускаем цикл. Он пройдется по строке меняет регистр всех ее букв пока не дойдет до конца */
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')	/* Если символ Верхнего регистра */
			argv[1][i] = argv[1][i] + 32;			/* то прибавляем к нему 32 чтоб переделать символ в нижний регистр */
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')	/* Если символ нижнего регистра */
			argv[1][i] = argv[1][i] - 32;					/* то вычитаем из него 32 чтоб переделать символ в Верхний регистр */
		write(1, &argv[1][i], 1);					/* Печатаем ячейку массива которую мы изменили */
		i++;										/* Увеличиваем счетчик что бы перейти к след ячейке */
	}
	write(1,'\n',1);				/* Печатаем символ перехода на новую строку */
	return (0);						/* Завершаем программу */
}

/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	letter;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
				letter += 32;
			if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
				letter -= 32;
			write(1, &letter, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}