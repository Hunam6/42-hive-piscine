/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:19:47 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/13 18:02:22 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	factor;

	if (nb < 2)
	{
		return (0);
	}
	factor = 2;
	while (nb > 1)
	{
		if (nb % factor == 0)
		{
			if (factor != nb)
			{
				return (0);
			}
			nb /= factor;
		}
		else
		{
			factor++;
		}
	}
	return (1);
}
