/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:01:52 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/26 13:15:22 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

typedef struct s_level_infos
{
	void	(*applyf)(
			void *item,
			int current_level,
			int is_first_elem
			);
	int		current_level;
	int		is_first_elem;
}	t_level_infos;

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	int	left_levels;
	int	right_levels;

	if (root == NULL)
		return (0);
	left_levels = btree_level_count(root->left);
	right_levels = btree_level_count(root->right);
	return (max(left_levels, right_levels) + 1);
}

void	do_level(t_btree *root, int level, t_level_infos *infos)
{
	if (root == NULL)
		return ;
	if (level == 0)
	{
		infos->applyf(root->item, infos->current_level, infos->is_first_elem);
		infos->is_first_elem = 0;
	}
	else
	{
		do_level(root->left, level - 1, infos);
		do_level(root->right, level - 1, infos);
	}
}

void	btree_apply_by_level(
	t_btree	*root,
	void (*applyf)(
				void *item,
				int current_level,
				int is_first_elem
			)
)
{
	int				height;
	int				i;
	t_level_infos	*infos;

	height = btree_level_count(root);
	infos = malloc(sizeof(t_level_infos));
	infos->applyf = applyf;
	i = 0;
	while (i < height)
	{
		infos->is_first_elem = 1;
		infos->current_level = i;
		do_level(root, i, infos);
		i++;
	}
}
