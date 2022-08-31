/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:19:47 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/13 19:40:47 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;

	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	sum = 1;
	while (nb > 0)
	{
		sum *= nb;
		nb--;
	}
	return (sum);
}
