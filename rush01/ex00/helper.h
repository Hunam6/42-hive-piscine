/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:40:02 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/21 16:52:31 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
# include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_corner(int nb)
{
	int	i;
	int	corner;

	i = 0;
	corner = 0;
	while (i < nb)
	{
		if ((i + 1) % 3 == 0)
			corner += 3;
		i++;
	}
	return (corner);
}

#endif