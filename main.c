
#include "functions.h"

void	ft_error()
{
	write (1, "error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if(!(check_is_valid(argv[1])))
			ft_error();
		ft_putnbr(eval_expr(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}