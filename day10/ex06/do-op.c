/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:39:37 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/22 18:35:18 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "libft.h"

int	(*g_ops[5])(int, int) = {add, min, mul, div, mod};

int	calc(int num1, char op, int num2)
{
	if (op == '+')
		return (g_ops[0](num1, num2));
	else if (op == '-')
		return (g_ops[1](num1, num2));
	else if (op == '*')
		return (g_ops[2](num1, num2));
	else if (op == '/')
		return (g_ops[3](num1, num2));
	return (g_ops[4](num1, num2));
}

int	is_div_mod_zero(char op)
{
	if (op == '/')
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (op == '%')
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	op;

	if (argc != 4)
		return (0);
	if (argv[2][0] == '"')
		op = argv[2][1];
	else
		op = argv[2][0];
	if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
	{
		ft_putstr("0\n");
		return (0);
	}
	if (ft_atoi(argv[3]) == 0 && is_div_mod_zero(op))
		return (0);
	ft_putnbr(calc(ft_atoi(argv[1]), op, ft_atoi(argv[3])));
	ft_putchar('\n');
}
