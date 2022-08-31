/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:34:01 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/23 19:23:37 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		len;
	t_list	*current_node;

	if (begin_list == NULL)
		return (0);
	len = 1;
	current_node = begin_list;
	while (current_node->next)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}
