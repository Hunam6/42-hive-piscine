/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:34:01 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/23 19:35:33 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*old_first_node;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	old_first_node = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = old_first_node;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*out;

	i = 0;
	out = NULL;
	while (i < ac)
		ft_list_push_front(&out, av[i++]);
	return (out);
}
