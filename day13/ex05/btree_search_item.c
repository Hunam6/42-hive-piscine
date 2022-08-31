/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:01:52 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/25 16:53:43 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(
	t_btree *root,
	void *data_ref,
	int (*cmpf)(void *, void *)
)
{
	void	*left;
	void	*right;

	if (root == NULL)
		return (NULL);
	left = btree_search_item(root->left, data_ref, cmpf);
	if (left)
		return (left);
	if (cmpf(data_ref, root->item))
		return (root->item);
	right = btree_search_item(root->right, data_ref, cmpf);
	if (right)
		return (right);
	return (NULL);
}
