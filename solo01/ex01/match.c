/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:14:08 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/21 11:04:49 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	char	str_ch;
	char	match_ch;

	while (1)
	{
		str_ch = *s1;
		match_ch = *s2;
		if (match_ch == '\0')
			return (str_ch == '\0');
		if (match_ch == '*')
		{
			if (match(s1, s2 + 1))
				return (1);
			if (str_ch == '\0')
				return (0);
		}
		else
		{
			if (match_ch != str_ch)
				return (0);
			s2++;
		}
		s1++;
	}
}
