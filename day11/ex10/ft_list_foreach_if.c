/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:34:01 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/24 15:45:04 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(
	t_list *begin_list,
	void (*f)(void *),
	void *data_ref,
	int (*cmp)(void *, void *)
)
{
	t_list	*node;

	node = begin_list;
	while (node != NULL)
	{
		if (cmp(node->data, data_ref))
			f(node->data);
		node = node->next;
	}
}
