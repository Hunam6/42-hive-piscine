/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:37:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/17 17:47:52 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_size(int argc, char **argv)
{
	int	size;
	int	idx;

	size = 0;
	idx = 0;
	while (idx < argc)
	{
		size += sizeof(argv[idx]);
		idx++;
	}
	return (size);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*out;
	int		idx_arg;
	int		idx_out;
	int		idx;

	out = malloc(get_size(argc, argv));
	idx_arg = 0;
	idx_out = 0;
	while (idx_arg < argc)
	{
		idx = 0;
		while (argv[idx_arg][idx] != '\0')
		{
			out[idx_out] = argv[idx_arg][idx];
			idx++;
			idx_out++;
		}
		if (idx_arg + 1 != argc)
			out[idx_out++] = '\n';
		idx_arg++;
	}
	return (out);
}
