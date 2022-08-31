/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:59:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/24 19:51:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		write(1, &str[idx++], 1);
}

int	main(int argc, char **argv)
{
	int		file_descriptor;
	int		i;
	char	ch;

	i = 1;
	while (i < argc)
	{
		file_descriptor = open(argv[i], O_RDONLY);
		if (file_descriptor == -1)
		{
			errno = ENOENT;
			ft_putstr("cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
			i++;
			continue ;
		}
		while (read(file_descriptor, &ch, 1))
			write(1, &ch, 1);
		close(file_descriptor);
		i++;
	}
}
