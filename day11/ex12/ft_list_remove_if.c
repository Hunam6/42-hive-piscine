/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:34:01 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/24 17:35:58 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev;
	t_list	*node;

	prev = NULL;
	node = begin_list;
	while (node != NULL)
	{
		if (cmp(node->data, data_ref))
		{
			if (prev == NULL)
				begin_list = node->next;
			else
				prev->next = node->next;
		}
		prev = node;
		node = node->next;
	}
}
