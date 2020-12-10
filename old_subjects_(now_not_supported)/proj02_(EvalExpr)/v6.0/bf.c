#include <unistd.h>

int main(int ac, char **av) {
	if (ac != 2) {
		ierr:
		write(1, "\n", 1);
		return 0;
	}
	char buff[2048] = {0};
	char *ptr = av[1];
	int i = 0;
	int loop;
	while (*ptr) {
		switch (*ptr) {
			case '>':
				++i;
				goto next;
			case '<':
				--i;
				goto next;
			case '+':
				++buff[i];
				goto next;
			case '-':
				--buff[i];
				goto next;
			case '.':
				write(1, buff + i, 1);
				goto next;
			case '[':
				loop = 1;
				if (buff[i] != 0) goto next;
				while (*(ptr + 1) && loop) {
					++ptr;
					if (*ptr == '[') ++loop;
					else if (*ptr == ']' ) --loop;
				}
				break;
			case ']':
				loop = 1;
				if (buff[i] == 0) goto next;
				while (*(ptr - 1) && loop) {
					--ptr;
					if (*ptr == ']') ++loop;
					else if (*ptr == '[' ) --loop;
				}
				break;
			next:
			default:
				++ptr;
		}
	}
	goto ierr;
}

/*int		ft_ee_expr(const char *str, long *offset);

int		ft_ee_primary(const char *str, long *offset)
{
	int a;

	while (IS_WS(PEEK(str, *offset)))
		INEXT(*offset);
	if (PEEK(str, *offset) == '(')
    {
        INEXT(*offset);
        a = ft_ee_expr(str, offset);
        INEXT(*offset);
        return (a);
    }
	return (ft_ee_atoi(str, offset));
}

int		ft_ee_multiplicative(const char *str, long *offset)
{
	int		a;
	char 	c;

	a = ft_ee_primary(str, offset);
	while (1)
		if ((c = PEEK(str, *offset)) == ' ')
			INEXT(*offset);
		else if (c == OP_MUL ? ++*offset : 0)
			a *= ft_ee_primary(str, offset);
		else if (c == OP_DIV ? ++*offset : 0)
			a /= ft_ee_primary(str, offset);
		else if (c == OP_MOD ? ++*offset : 0)
			a %= ft_ee_primary(str, offset);
		else
			return (a);
}

int		ft_ee_expr(const char *str, long *offset)
{
	int 	a;
	char	c;

	a = ft_ee_multiplicative(str, offset);
	while (1)
		if ((c = PEEK(str, *offset)) == ' ')
			INEXT(*offset);
		else if (c == OP_ADD ? ++*offset : 0)
			a += ft_ee_multiplicative(str, offset);
		else if (c == OP_SUB ? ++*offset : 0)
			a -= ft_ee_multiplicative(str, offset);
		else
			return (a);
}*/
