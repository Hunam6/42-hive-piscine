/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:55 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/14 16:40:47 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_putchar.c"

void	horizontal_line(int x, int y)
{
	int	idx;

	idx = 0;
	ft_putchar('A');
	while (idx < x - 2)
	{
		ft_putchar('B');
		idx++;
	}
	if (x > 1)
	{
		ft_putchar('C');
	}
}

void	vertical_lines(int x, int y)
{
	int	idx;
	int	idx_in;

	idx = 0;
	while (idx < y - 2)
	{
		ft_putchar('B');
		idx_in = 0;
		while (idx_in < x - 2)
		{
			ft_putchar(' ');
			idx_in++;
		}
		if (x > 1)
		{
			ft_putchar('B');
		}
		ft_putchar('\n');
		idx++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	horizontal_line(x, y);
	if (y > 1)
	{
		ft_putchar('\n');
	}
	vertical_lines(x, y);
	if (y > 1)
	{
		horizontal_line(x, y);
	}
	ft_putchar('\n');
}
