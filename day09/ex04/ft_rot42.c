/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:12:46 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 22:13:53 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_letter(char ch)
{
	return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));
}

char	*ft_rot42(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		str[idx] += 42 - 26;
		if (!is_letter(str[idx]))
			str[idx] -= 26;
		idx++;
	}
	return (str);
}
