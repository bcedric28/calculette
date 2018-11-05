
#include "functions.h"

static int		check_brackets_valid(char *str)
{
	int count;
	int i;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			count++;
		if (str[i] == ')')
			count--;
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

static int		check_brackets(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ')')
			return (0);
		if (str[i] == '(')
		{
			if(!(check_brackets_valid(&str[i + 1])))
				return (0);
			break ;
		}
		i++;
	}
	return(1);
}

int		check_is_valid(char *str)
{
	int i;
	int op;
	int valid;

	valid = 0;
	op = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			valid = 1;
			break ;
		}
		i++;
	}
	if (valid == 0)
	{
		ft_putendl(str);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-' &&
			str[i] != '/' && str[i] != '*' && str[i] != '%' && str[i] != '(' && 
			str[i] != ')' && str[i] != ' ')
			return (0);
		if (str[i] == '+' || str[i] == '-' ||
			str[i] == '/' || str[i] == '*' || str[i] == '%')
			op++;
		i++;
	}
	if (op == 0)
		return (0);
	if(!(check_brackets(str)))
		return (0);
	return (1);
}