/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:12:46 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 21:10:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base > 1)
	{
		if (base % 2)
			return (1 + ft_collatz_conjecture(3 * base + 1));
		else
			return (1 + ft_collatz_conjecture(base / 2));
	}
	return (0);
}
