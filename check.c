

#include "functions.h"

static int		check_parenthesis(char **str);
static int		check_multip(char **str);
static int		check_expression(char **str);


static int		check_parenthesis(char **str)
{
	int		nbr;
	int		signe;

	nbr = 0;
	signe = 1;
	if ((*str)[0] == '+' || (*str)[0] == '-')
	{
		if ((*str)[0] == '-')
			signe = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(')
	{
		*str = *str + 1;
		nbr = check_expression(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (signe * nbr);
	}
	while ('0' <= (*str)[0] && (*str)[0] <= '9')
	{
		nbr = (nbr * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (signe * nbr);
}

static int		check_multip(char **str)
{
	int		nb1;
	int		nb2;
	char	operator;

	nb1 = check_parenthesis(str);
	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%')
	{
		operator = (*str)[0];
		*str = *str + 1;
		nb2 = check_parenthesis(str);
		nb1 = calcul_op(nb1, nb2, operator);
	}
	return (nb1);
}

static int		check_expression(char **str)
{
	int		nb1;
	int		nb2;
	char	operator;

	nb1 = check_parenthesis(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		operator = (*str)[0];
		*str = *str + 1;
		if (operator == '+' || operator == '-')
			nb2 = check_multip(str);
		else
			nb2 = check_parenthesis(str);
		nb1 = calcul_op(nb1, nb2, operator);
	}
	return (nb1);
}

static char	*delete_whitespaces(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

int		eval_expr(char *str)
{
	str = delete_whitespaces(str);
	if (str[0] == '\0')
		return (0);
	return (check_expression(&str));
}