/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:37:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 19:36:40 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	idx;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = sizeof(int) * (max - min);
	*range = malloc(size);
	idx = 0;
	while (idx < max - min)
	{
		*(*range + idx) = min + idx;
		idx++;
	}
	return (max - min);
}
