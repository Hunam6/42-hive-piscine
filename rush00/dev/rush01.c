/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:55 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/16 10:06:46 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_putchar.c"

void	horizontal_line(int x, int y, int is_first)
{
	int	idx;

	idx = 0;
	if (is_first)
		ft_putchar('/');
	else
		ft_putchar('\\');
	while (idx < x - 2)
	{
		ft_putchar('*');
		idx++;
	}
	if (x > 1)
	{
		if (is_first)
			ft_putchar('\\');
		else
			ft_putchar('/');
	}
}

void	vertical_lines(int x, int y)
{
	int	idx;
	int	idx_in;

	idx = 0;
	while (idx < y - 2)
	{
		ft_putchar('*');
		idx_in = 0;
		while (idx_in < x - 2)
		{
			ft_putchar(' ');
			idx_in++;
		}
		if (x > 1)
		{
			ft_putchar('*');
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
	horizontal_line(x, y, 1);
	if (y > 1)
	{
		ft_putchar('\n');
	}
	vertical_lines(x, y);
	if (y > 1)
	{
		horizontal_line(x, y, 0);
	}
	ft_putchar('\n');
}
