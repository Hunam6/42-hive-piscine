/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:01:52 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/25 18:02:43 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

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
