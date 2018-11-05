
#include "functions.h"

int	calcul_op(int nb1, int nb2, char operator)
{
	if (operator == '+')
		return (nb1 + nb2);
	else if (operator == '-')
		return (nb1 - nb2);
	else if (operator == '/')
	{
		if (nb2 == 0)
		{
			ft_putendl("error");
			exit(EXIT_FAILURE);
		}
		return (nb1 / nb2);
	}
	else if (operator == '*')
		return (nb1 * nb2);
	else if (operator == '%')
	{
		if (nb2 == 0)
		{
			ft_putendl("error");
			exit(EXIT_FAILURE);
		}
		return (nb1 % nb2);
	}
	return (0);
}
