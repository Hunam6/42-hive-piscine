/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:45:02 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/22 12:03:33 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

void	solve(t_sudoku *sudoku);

void	fill(t_sudoku *sudoku, int i, int j)
{
	char	nb;

	nb = '1';
	while (nb <= '9')
	{
		if (possible(sudoku, i, j, nb))
		{
			sudoku->grid[i][j] = nb;
			solve(sudoku);
			sudoku->grid[i][j] = '.';
		}
		nb++;
	}
}

void	solution_found(t_sudoku *sudoku)
{
	if (sudoku->solution_found == 1)
	{
		ft_putstr("Error\n");
		sudoku->solution_found++;
	}
	if (sudoku->solution_found == 0)
	{
		set_completed_grid(sudoku);
		sudoku->solution_found = 1;
	}
}

void	solve(t_sudoku *sudoku)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (sudoku->grid[i][j] == '.')
			{
				fill(sudoku, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_putstr("one solution\n");
	solution_found(sudoku);
}

int	main(int argc, char *argv[])
{
	t_sudoku	sudoku;

	init_grid(&sudoku, argc, argv);
	solve(&sudoku);
	if (sudoku.solution_found == 1)
		print(&sudoku);
	if (sudoku.solution_found == 0)
		ft_putstr("Error\n");
}
