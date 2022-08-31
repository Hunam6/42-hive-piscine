/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:37:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/17 15:49:58 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	idx;

	if (min >= max)
		return ((int *) NULL);
	array = malloc(sizeof(int) * (max - min));
	idx = 0;
	while (idx < max - min)
	{
		*(array + idx) = min + idx;
		idx++;
	}
	return (array);
}
