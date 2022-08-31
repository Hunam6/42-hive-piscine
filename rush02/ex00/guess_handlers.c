/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:25:07 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:43:54 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush/rush.h"
#include "input_utils.h"
#include "guess_handlers.h"

void	(*g_rushes[5])(t_string *, int, int) = {
	rush00, rush01, rush02, rush03, rush04
};

char	*get_ref(int guess, int width, int height)
{
	t_string	*out;

	out = malloc(sizeof(t_string));
	out->str = malloc(sizeof(char) * ((width + 1) * height));
	out->len = 0;
	g_rushes[guess](out, width, height);
	append(out, '\0');
	return (out->str);
}

void	get_guesses_a(int guesses[4], char *input, int width, int height)
{
	int	i;

	i = 0;
	if (width == 1 && height == 1)
	{
		guesses[i++] = 2;
		guesses[i++] = 3;
		guesses[i++] = 4;
	}
	else if (input[width - 1] == 'C' && height == 1)
	{
		guesses[i++] = 3;
		guesses[i++] = 4;
	}
	else if (input[width - 1] == 'A')
		guesses[0] = 2;
	else if (input[(width + 1) * height - 2] == 'C')
		guesses[0] = 3;
	else if (input[(width + 1) * height - 2] == 'A')
		guesses[0] = 4;
}

int	cmp_guesses(int guesses[4], char *input, int width, int height)
{
	char	*ref;
	int		i;

	i = 0;
	while (guesses[i] != -1)
	{
		ref = get_ref(guesses[i], width, height);
		if (ft_strcmp(input, ref) == 0)
			return (1);
		i++;
	}
	putstr("none\n");
	return (0);
}

void	print_guess(int guess, int width, int height)
{
	putstr("[rush-0");
	putnb(guess);
	putstr("] [");
	putnb(width);
	putstr("] [");
	putnb(height);
	putstr("]");
}

void	print_guesses(int guesses[4], int width, int height)
{
	int	i;

	if (guesses[1] == -1)
		print_guess(guesses[0], width, height);
	else
	{
		i = 0;
		while (guesses[i] != -1)
		{
			print_guess(guesses[i], width, height);
			if (guesses[i + 1] != -1)
				putstr(" || ");
			i++;
		}
	}
	putch('\n');
}
