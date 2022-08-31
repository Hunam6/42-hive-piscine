/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:29:56 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:44:06 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	char			data;
}	t_list;

typedef struct s_string
{
	char	*str;
	int		len;
}				t_string;

t_list	*ft_create_elem(char data);
void	ft_list_push_back(t_list **begin_list, char data);
int		ft_list_size(t_list *begin_list);
void	ft_list_clear(t_list **begin_list);
void	append(t_string *str, char ch);

#endif