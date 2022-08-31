/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:26:33 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/14 23:43:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	handle_even_executed(int *part_idx, int *diff_between_lvl, int *door_size)
{
	if (*part_idx % 2 == 0)
	{
		(*diff_between_lvl)++;
		if (*part_idx > 0)
			*door_size += 2;
	}
}

void	print_spaces_slash(int *line_idx, int max_half_width, int asterix_nb)
{
	*line_idx = 0;
	while (*line_idx < max_half_width - ((asterix_nb - 1) / 2) + 1)
	{
		ft_putchar(' ');
		(*line_idx)++;
	}
	ft_putchar('/');
	*line_idx = 0;
}

void	print_asterixes_backslash_newline(int *line_idx, int *asterix_nb)
{
	while (*line_idx < *asterix_nb)
	{
		ft_putchar('*');
		(*line_idx)++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
	*asterix_nb += 2;
}

void	print_beg_line(int *line_idx, int max_half_width, int *asterix_nb)
{
	print_spaces_slash(line_idx, max_half_width, *asterix_nb);
	print_asterixes_backslash_newline(line_idx, asterix_nb);
}

void	generate(int size, int max_half_width)
{
	int	part_idx;
	int	height_idx;
	int	line_idx;
	int	current_height;
	int	asterix_nb;
	int	diff_between_lvl;
	int	door_size;
	int	is_door_line;
	int	door_idx;

	door_size = 1;
	is_door_line = 0;
	asterix_nb = 1;
	diff_between_lvl = 1;
	part_idx = 0;
	while (part_idx < size)
	{
		handle_even_executed(&part_idx, &diff_between_lvl, &door_size);
		current_height = 2 + part_idx;
		height_idx = 0;
		while (height_idx <= current_height && !is_door_line)
		{
			print_beg_line(&line_idx, max_half_width, &asterix_nb);
			is_door_line = (part_idx + 1 == size) && ((height_idx) >= (current_height - door_size));
			height_idx++;
		}
		while (height_idx <= current_height && is_door_line)
		{
			print_spaces_slash(&line_idx, max_half_width, asterix_nb);
			while (line_idx < (asterix_nb - door_size) / 2)
			{
				ft_putchar('*');
				line_idx++;
			}
			door_idx = 0;
			while (door_idx < door_size)
			{
				if (size > 4 && door_idx == door_size - 2 && height_idx - 1 == ((current_height - door_size) + (door_size / 2)))
					ft_putchar('$');
				else
					ft_putchar('|');
				door_idx++;
				line_idx++;
			}
			print_asterixes_backslash_newline(&line_idx, &asterix_nb);
			height_idx++;
		}
		asterix_nb += diff_between_lvl * 2;
		part_idx++;
	}
}

void	sastantua(int size)
{
	int	current_part_heigth;
	int	max_half_width;
	int	diff_between_lvl;
	int	idx1;
	int	idx2;

	diff_between_lvl = 2;
	current_part_heigth = 3;
	max_half_width = 0;
	idx1 = 0;
	while (idx1 < size)
	{
		idx2 = 0;
		while (idx2 < current_part_heigth)
		{
			max_half_width++;
			idx2++;
		}
		if (idx1 + 1 != size)
			max_half_width += diff_between_lvl;
		if (idx1 % 2 != 0)
			diff_between_lvl++;
		current_part_heigth++;
		idx1++;
	}
	generate(size, max_half_width - 2);
}
