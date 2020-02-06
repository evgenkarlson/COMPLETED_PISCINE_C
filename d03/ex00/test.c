#include <unistd.h>

int 	ft_putchar(char n)		/* функция вывода символа */
{
	write(1, &n, 1);

	return (0);
}

void	ft_putnbr(int nb)     		 /* Функция вывода числа */
{
	int		temp;
	int		size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)(temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
/* #######################################################################*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int		main(void)
{
	int		i;			/*обьявляем мпеременную типа инт */

	i = 21;				/*ЗАпишем туда число 21 для проверки*/
	ft_ft(&i);			/* Отправляем адрес этой переменной в функцию 
						чтобы там с помощью операции разыменовывания можно было поменять данные,
						которые хранятся по адресу который мы кинули в функцию */

	ft_putnbr(i + '0');	/* ПРоверяем изменилось ли число с 21 на 42 */

	return (0);
}


