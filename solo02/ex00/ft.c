/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:10:04 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 11:00:49 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb);

int	ft_handle_special_cases(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return (nb);
		}
		return (-nb);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	str[11];
	int		idx;
	int		remainder;

	idx = 0;
	nb = ft_handle_special_cases(nb);
	while (nb > 0)
	{
		remainder = nb % 10;
		nb /= 10;
		str[idx++] = '0' + remainder;
	}
	str[idx] = '\0';
	while (idx >= 0)
	{
		ft_putchar(str[idx]);
		idx--;
	}
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
