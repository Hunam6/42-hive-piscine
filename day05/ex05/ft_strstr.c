/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:56:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/16 19:26:29 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		idx_str;
	int		idx_to_find;
	char	*guess;

	idx_str = 0;
	idx_to_find = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[idx_str] != '\0')
	{
		if (to_find[idx_to_find] != str[idx_str])
			idx_to_find = 0;
		if (to_find[idx_to_find] == str[idx_str])
		{
			guess = &str[idx_str];
			idx_to_find++;
		}
		if (to_find[idx_to_find] == '\0')
			return (guess - idx_to_find + 1);
		idx_str++;
	}
	return ((void *) 0);
}
