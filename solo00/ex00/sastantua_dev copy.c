/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua_dev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:26:29 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/14 22:15:02 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void line(int todo)
{
	todo = 45; // TODO: remove this
}
void part(int size)
{
	int height;
	int width;
	int current_height;
	int current_width;

	size = 45; // TODO: remove this

	height = 3;
	current_height = 1; // TODO: add 2 for each size level
	width = 7;
	while (current_height <= height)
	{
		// ` `
		current_width = 0;
		while (current_width < height-current_height)
		{
			ft_putchar(' ');
			current_width++;
		}
		// `/`
		ft_putchar('/');
		// `*`
		current_width = 0;
		while (current_width < width-height-current_height)
		{
			ft_putchar('*');
			current_width += 2;
		}
		// `\`
		ft_putchar('\\');
		// `\n`
		ft_putchar('\n');
		current_height++;
	}
}

void generate(int size, int max_half_width)
{
	int base_height;
	int part_idx;
	int height_idx;
	int line_idx;
	int current_height;
	int asterix_nb;
	int diff_between_lvl;
	int consecutive_lvl_same;
	// door
	int door_height;
	int door_width;
	int is_door_line;
	int door_idx;

	door_height = 1;
	door_width = 1;
	is_door_line = 0;
	asterix_nb = 1;
	diff_between_lvl = 2;
	consecutive_lvl_same = 0;
	// parts
	part_idx = 0;
	while (part_idx < size)
	{
		if (part_idx % 2 == 0 && part_idx > 0)
		{
			// door
			door_height += 2;
			door_width += 2;
		}
		if (consecutive_lvl_same == 2)
		{
			diff_between_lvl++;
			consecutive_lvl_same = 0;
		}
		current_height = 2 + part_idx;
		// lines
		height_idx = 0;
		// usual line
		while (height_idx <= current_height && !is_door_line)
		{
			// spaces
			line_idx = 0;
			while (line_idx < max_half_width - ((asterix_nb - 1) / 2) + 1)
			{
				ft_putchar(' ');
				line_idx++;
			}
			// slash
			ft_putchar('/');
			// asterixes
			line_idx = 0;
			while (line_idx < asterix_nb)
			{
				ft_putchar('*');
				line_idx++;
			}
			// backslash
			ft_putchar('\\');
			// newline
			ft_putchar('\n');
			asterix_nb += 2;
			is_door_line = (part_idx + 1 == size) && ((height_idx) >= (current_height - door_height)); //TODO: check this
			//printf("part_idx> %d\n", part_idx);
			//printf("> %d\n", is_door_line);
			//printf("(current_height - door_height)> %d\n", (current_height - door_height));
			//printf("height_idx> %d\n", height_idx);
			height_idx++;
		}
		// door line
		while (height_idx <= current_height && is_door_line)
		{
			// spaces
			line_idx = 0;
			//TODO: fix size=1
			while (line_idx < max_half_width - ((asterix_nb - 1) / 2) + 1)
			{
				ft_putchar(' ');
				line_idx++;
			}
			// slash
			ft_putchar('/');
			// asterixes before
			line_idx = 0;
			while (line_idx < (asterix_nb - door_width) / 2)
			{
				ft_putchar('*');
				line_idx++;
			}
			// door
			door_idx = 0;
			while (door_idx < door_width)
			{
				if (size > 4 && door_idx == door_width - 2 && height_idx - 1 == ((current_height - door_height) + (door_height / 2)))
				{
					ft_putchar('$');
				}
				else
				{
					ft_putchar('|');
				}
				door_idx++;
				line_idx++;
			}
			// asterixes after
			while (line_idx < asterix_nb)
			{
				ft_putchar('*');
				line_idx++;
			}
			// backslash
			ft_putchar('\\');
			// newline
			ft_putchar('\n');
			asterix_nb += 2;
			is_door_line = (part_idx + 1 == size) && ((height_idx + 1) >= (current_height - door_height));
			height_idx++;
		}
		consecutive_lvl_same++;
		asterix_nb += diff_between_lvl * 2;
		part_idx++;
	}
}


void	sastantua(int size)
{
	int current_part_heigth;
	int max_half_width;
	int diff_between_lvl;
	int consecutive_lvl_same;
	int idx1;
	int idx2;

	diff_between_lvl = 2;
	consecutive_lvl_same = 0;
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
		{
			max_half_width += diff_between_lvl;
		}
		if (idx1 % 2 != 0)
		{
			diff_between_lvl++;
		}
		current_part_heigth++;
		idx1++;
	}
	generate(size, max_half_width - 2);
}

int  main(void)
{
 	sastantua(1);
	printf("---\n");
	sastantua(2);
 	printf("---\n");
	sastantua(3);
	printf("---\n");
	sastantua(4);
	printf("---\n");
	sastantua(5);
	printf("---\n");
	sastantua(6);
	printf("---\n");
	sastantua(7);
	printf("---\n");
	sastantua(8);
	printf("---\n");
	sastantua(9);
}