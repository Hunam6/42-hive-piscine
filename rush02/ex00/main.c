/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:29:09 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:33:28 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "input_utils.h"
#include "ft_helpers.h"
#include "guess_handlers.h"

char	*get_input(void)
{
	t_list	*list;
	t_list	*current_node;
	char	ch;
	int		i;
	char	*out;

	list = NULL;
	while (read(0, &ch, 1))
		ft_list_push_back(&list, ch);
	if (ch == '\0')
	{
		putstr("none\n");
		return (NULL);
	}
	out = malloc(sizeof(char) * (ft_list_size(list) + 1));
	current_node = list;
	i = 0;
	while (current_node != NULL)
	{
		out[i++] = current_node->data;
		current_node = current_node->next;
	}
	ft_list_clear(&list);
	out[i] = '\0';
	return (out);
}

int	get_height(char *input)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			height++;
		i++;
	}
	return (height);
}

int	get_width(char *input, int height)
{
	int	width;
	int	pos;
	int	i;

	width = 0;
	pos = 0;
	i = 0;
	while (input[pos] != '\n')
		pos++;
	width = pos;
	while (i < height)
	{
		if (input[pos] != '\n')
		{
			putstr("none\n");
			return (-1);
		}
		pos += width + 1;
		i++;
	}
	return (width);
}

void	get_guesses(int guesses[4], char *input, int width, int height)
{
	int	i;

	i = 0;
	guesses[0] = -1;
	guesses[1] = -1;
	guesses[2] = -1;
	guesses[3] = -1;
	if (input[0] == 'o')
		guesses[0] = 0;
	else if (input[0] == '/')
		guesses[0] = 1;
	else if (input[0] == 'A')
		get_guesses_a(guesses, input, width, height);
	if (guesses[0] == -1)
		putstr("none\n");
}

int	main(void)
{
	char	*input;
	int		width;
	int		height;
	int		guesses[4];
	int		correct;

	input = get_input();
	if (input == NULL)
		return (0);
	height = get_height(input);
	width = get_width(input, height);
	if (width == -1)
		return (0);
	get_guesses(guesses, input, width, height);
	if (guesses[0] == -1)
		return (0);
	correct = cmp_guesses(guesses, input, width, height);
	if (!correct)
		return (0);
	print_guesses(guesses, width, height);
}
