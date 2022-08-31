/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:12:46 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 17:10:28 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	good_to_bad_num(int hour)
{
	if (hour == 25)
		return (1);
	if (hour == 0 || hour == 24)
		return (12);
	if (13 <= hour && hour <= 23)
		return (hour - 12);
	return (hour);
}

char	good_to_bad_letter(int hour)
{
	if ((0 <= hour && hour <= 11) || hour >= 24)
		return ('A');
	return ('P');
}

void	ft_takes_place(int hour)
{
	printf(
		"THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.\n\n",
		good_to_bad_num(hour),
		good_to_bad_letter(hour),
		good_to_bad_num(hour + 1),
		good_to_bad_letter(hour + 1)
		);
}
