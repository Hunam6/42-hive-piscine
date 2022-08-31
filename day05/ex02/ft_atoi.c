/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:56:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/15 17:50:16 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char ch)
{
	return ('0' <= ch && ch <= '9');
}

int	ft_atoi(char *str)
{
	int	res;
	int	idx;
	int	is_pos;

	if (!(str[0] == '-' || str[0] == '+' || is_number(str[0])))
		return (0);
	res = 0;
	idx = 0;
	if (str[0] == '-')
	{
		idx++;
		is_pos = 0;
	}
	if (str[0] == '+')
		idx++;
	while (str[idx] != '\0')
	{
		if (!is_number(str[idx]))
			break ;
		res = res * 10 + (str[idx] - 48);
		idx++;
	}
	if (is_pos)
		return (res);
	return (-res);
}
