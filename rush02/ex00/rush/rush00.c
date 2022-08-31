/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:55 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:56:14 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	horizontal_line00(t_string *out, int x)
{
	int	idx;

	idx = 0;
	append(out, 'o');
	while (idx < x - 2)
	{
		append(out, '-');
		idx++;
	}
	if (x > 1)
		append(out, 'o');
}

void	vertical_lines00(t_string *out, int x, int y)
{
	int	idx;
	int	idx_in;

	idx = 0;
	while (idx < y - 2)
	{
		append(out, '|');
		idx_in = 0;
		while (idx_in < x - 2)
		{
			append(out, ' ');
			idx_in++;
		}
		if (x > 1)
		{
			append(out, '|');
		}
		append(out, '\n');
		idx++;
	}
}

void	rush00(t_string *out, int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	horizontal_line00(out, x);
	if (y > 1)
	{
		append(out, '\n');
	}
	vertical_lines00(out, x, y);
	if (y > 1)
	{
		horizontal_line00(out, x);
	}
	append(out, '\n');
}
