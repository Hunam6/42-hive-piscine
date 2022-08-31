/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:59:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/25 10:32:34 by etattevi         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

void	single_file(int ch_nb, char *file_path)
{
	
}

int	main(int argc, char **argv)
{
	int		file_descriptor;
	int		i;
	char	ch;

	if (argc < 4)
		return (1);
	if (argc == 4)
		single_file(ft_atoi(argv[2]), argv[3]);
	else
	{
		i = 3;
		while (i < argc)
		{
			put_str("==> ");
			put_str(argv[i]);
			put_str(" <==\n");
			single_file(ft_atoi(argv[2]), argv[i]);
		}
	}
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
