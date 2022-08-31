/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:56:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/15 20:46:49 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upperalpha(char ch)
{
	return ('A' <= ch && ch <= 'Z');
}

int	is_loweralpha(char ch)
{
	return ('a' <= ch && ch <= 'z');
}

int	is_alphanumeric(char ch)
{
	return (
		(is_upperalpha(ch))
		|| (is_loweralpha(ch))
		|| ('0' <= ch && ch <= '9')
	);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	next_cap;

	idx = 0;
	next_cap = 1;
	while (str[idx] != '\0')
	{
		if (next_cap && is_alphanumeric(str[idx]))
		{
			if (is_loweralpha(str[idx]))
				str[idx] -= 32;
			next_cap = 0;
		}
		else if (is_upperalpha(str[idx]))
			str[idx] += 32;
		else if (!is_alphanumeric(str[idx]))
			next_cap = 1;
		idx++;
	}
	return (str);
}
