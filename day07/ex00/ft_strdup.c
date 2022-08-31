/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:37:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 15:48:53 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	*ft_strdup(char *src)
{
	int		idx;
	char	*dest;

	idx = 0;
	dest = malloc(sizeof(*src) * ft_strlen(src));
	if (dest == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (dest);
}
