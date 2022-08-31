/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:21:50 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:52:39 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helpers.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0' && s1[idx] == s2[idx])
		idx++;
	if (s1[idx] == s2[idx])
		return (0);
	return (s1[idx] - s2[idx]);
}

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	putch(char ch)
{
	write(1, &ch, 1);
}

void	putnb(int nb)
{
	if (nb >= 10)
	{
		putnb(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		putch(nb + '0');
}
