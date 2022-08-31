/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:59:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/25 14:39:25 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	put_err(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		write(2, &str[idx++], 1);
}

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	ch;

	if (argc == 1)
	{
		put_err("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		put_err("Too many arguments.\n");
		return (0);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	while (read(file_descriptor, &ch, 1))
		write(1, &ch, 1);
	close(file_descriptor);
}
