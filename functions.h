#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include <unistd.h>
#include <stdlib.h>
#include "Libft/includes/libft.h"

int		eval_expr(char *str);
int		calcul_op(int nb1, int nb2, char op);
int		check_is_valid(char *str);

#endif