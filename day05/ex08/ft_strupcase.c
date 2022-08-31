/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:56:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/15 19:57:30 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ('a' <= str[idx] && str[idx] <= 'z')
		{
			str[idx] -= 32;
		}
		idx++;
	}
	return (str);
}
