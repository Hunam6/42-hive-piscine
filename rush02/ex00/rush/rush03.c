/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:55 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:56:59 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	horizontal_line03(t_string *out, int x)
{
	int	idx;

	idx = 0;
	append(out, 'A');
	while (idx < x - 2)
	{
		append(out, 'B');
		idx++;
	}
	if (x > 1)
	{
		append(out, 'C');
	}
}

void	vertical_lines03(t_string *out, int x, int y)
{
	int	idx;
	int	idx_in;

	idx = 0;
	while (idx < y - 2)
	{
		append(out, 'B');
		idx_in = 0;
		while (idx_in < x - 2)
		{
			append(out, ' ');
			idx_in++;
		}
		if (x > 1)
		{
			append(out, 'B');
		}
		append(out, '\n');
		idx++;
	}
}

void	rush03(t_string *out, int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	horizontal_line03(out, x);
	if (y > 1)
	{
		append(out, '\n');
	}
	vertical_lines03(out, x, y);
	if (y > 1)
	{
		horizontal_line03(out, x);
	}
	append(out, '\n');
}
