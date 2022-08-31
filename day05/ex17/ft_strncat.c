/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:56:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/16 15:19:45 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		idx;
	char	*dest_start;

	idx = 0;
	dest_start = dest;
	dest += str_len(dest);
	while (src[idx] != '\0' && idx < nb)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (dest_start);
}
