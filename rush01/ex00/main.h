/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:05:33 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/21 17:07:10 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "helper.h"

typedef struct t_sudoku {
	char	**grid;
	char	**completed_grid;
	int		solution_found;
}	t_sudoku;

void	init_grid(t_sudoku *sudoku, int argc, char *argv[])
{
	int	i;
	int	j;

	sudoku->solution_found = 0;
	sudoku->grid = malloc(sizeof(char *) * 9);
	sudoku->completed_grid = malloc(sizeof(char *) * 9);
	i = 1;
	while (i < argc)
	{
		sudoku->grid[i - 1] = malloc(sizeof(char) * 9);
		sudoku->completed_grid[i - 1] = malloc(sizeof(char) * 9);
		j = 0;
		while (j < 9)
		{
			sudoku->grid[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
}

int	check_square(t_sudoku *sudoku, int y, int x, char nb)
{
	int	corner_y;
	int	corner_x;
	int	i;
	int	j;

	corner_y = get_corner(y);
	corner_x = get_corner(x);
	i = corner_y;
	while (i < corner_y + 3)
	{
		j = corner_x;
		while (j < corner_x + 3)
		{
			if (sudoku->grid[i][j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	possible(t_sudoku *sudoku, int y, int x, char ch)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (sudoku->grid[y][i] == ch)
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (sudoku->grid[i][x] == ch)
			return (0);
		i++;
	}
	return (check_square(sudoku, y, x, ch));
}

void	print(t_sudoku *sudoku)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(sudoku->completed_grid[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	set_completed_grid(t_sudoku *sudoku)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			sudoku->completed_grid[i][j] = sudoku->grid[i][j];
			j++;
		}
		i++;
	}
}

#endif