/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:19:47 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/13 18:03:13 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	guess;

	if (nb < 1)
	{
		return (0);
	}
	guess = nb;
	while (guess * guess > nb)
	{
		guess--;
	}
	if (guess * guess == nb)
	{
		return (guess);
	}
	return (0);
}
