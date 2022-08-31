/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:34:01 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/27 21:15:59 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"

t_list	*ft_create_elem(char data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->data = data;
	list->next = NULL;
	return (list);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list	*current_node;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	current_node = (*begin_list);
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = ft_create_elem(data);
}

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

void	ft_list_clear(t_list **begin_list)
{
	if ((*begin_list)->next)
		ft_list_clear(&((*begin_list)->next));
	free(*begin_list);
	*begin_list = NULL;
}

void	append(t_string *str, char ch)
{
	str->str[str->len] = ch;
	str->len++;
}
