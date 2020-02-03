#include <unistd.h>

int	main(void)
{
	int i;
	char a;
	char b;

	b = '\n';
	i = 0;
	while (i <= 25)
	{
		if((i % 2) == 0)
		{
			a = i + 97;
			write(1, &a, 1);
			i++;
		}
		else
		{
			a = i + 65;
			write(1, &a, 1);
			i++;
		}
	}
	write(1, &b, 1);
	return (0);
}