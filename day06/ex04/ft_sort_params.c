/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:53:19 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/17 19:20:58 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx++]);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0' && s1[idx] == s2[idx])
	{
		idx++;
	}
	if (s1[idx] == s2[idx])
	{
		return (0);
	}
	return (s1[idx] - s2[idx]);
}

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char *argv[])
{
	int		idx;
	int		idx_in;

	idx = 2;
	while (idx < argc)
	{
		idx_in = idx;
		while (idx_in > 1)
		{
			if (ft_strcmp(argv[idx_in - 1], argv[idx_in]) > 0)
				ft_swap_str(&argv[idx_in - 1], &argv[idx_in]);
			idx_in--;
		}
		idx++;
	}
	idx = 1;
	while (idx < argc)
	{
		ft_putstr(argv[idx]);
		ft_putchar('\n');
		idx++;
	}
}
