/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:12:46 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/19 10:29:59 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		write(1, &str[idx++], 1);
}

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

char	*ft_strlowcase(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ('A' <= str[idx] && str[idx] <= 'Z')
			str[idx] += 32;
		idx++;
	}
	return (str);
}

char	*trim(char *str)
{
	int	idx;
	int	begin;
	int	end;

	idx = 1;
	begin = 0;
	while (str[idx])
		idx++;
	end = idx - 1;
	while (str[begin] == ' ')
		begin++;
	while (str[end] == ' ')
		end--;
	idx = begin;
	while (idx <= end)
	{
		str[idx - begin] = str[idx];
		idx++;
	}
	str[idx - begin] = '\0';
	return (str);
}

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 0;
	while (idx < argc)
	{
		if (
			ft_strcmp(ft_strlowcase(trim(argv[idx])), "president") == 0
			|| ft_strcmp(ft_strlowcase(trim(argv[idx])), "attack") == 0
			|| ft_strcmp(ft_strlowcase(trim(argv[idx])), "powers") == 0
		)
			ft_putstr("Alert!!!\n");
		idx++;
	}
}
