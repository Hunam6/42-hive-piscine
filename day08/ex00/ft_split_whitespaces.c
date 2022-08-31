/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:37:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 16:00:06 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_arr_size(char *str)
{
	int	size;
	int	idx;

	size = 0;
	idx = 0;
	while (str[idx])
	{
		if (!(
				str[idx] == ' '
				|| str[idx] == '\t'
				|| str[idx] == '\n'
			))
			size += sizeof(char *);
		idx++;
	}
	return (size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
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

void	append_str(char **out, int *idx_arr, char *tmpstr, int *idx_tmpstr)
{
	out[*idx_arr] = malloc(sizeof(char) * (*idx_tmpstr + 1));
	tmpstr[*idx_tmpstr] = '\0';
	ft_strcpy(out[*idx_arr], tmpstr);
	(*idx_arr)++;
	*idx_tmpstr = 0;
}

char	**ft_split_whitespaces(char *str)
{
	int		idx_str;
	char	**out;
	int		idx_arr;
	char	*tmpstr;
	int		idx_tmpstr;

	idx_str = 0;
	out = malloc(get_arr_size(str));
	idx_arr = 0;
	tmpstr = malloc(sizeof(str));
	idx_tmpstr = 0;
	while (str[idx_str])
	{
		if (str[idx_str] == ' ' || str[idx_str] == '\t' || str[idx_str] == '\n')
			append_str(out, &idx_arr, tmpstr, &idx_tmpstr);
		else
			tmpstr[idx_tmpstr++] = str[idx_str];
		idx_str++;
	}
	append_str(out, &idx_arr, tmpstr, &idx_tmpstr);
	tmpstr[idx_tmpstr++] = '0';
	append_str(out, &idx_arr, tmpstr, &idx_tmpstr);
	return (out);
}
