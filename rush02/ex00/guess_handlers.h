/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:25:25 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 13:33:22 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESS_HANDLERS_H
# define GUESS_HANDLERS_H

# include <stdlib.h>
# include "ft_helpers.h"

char	*get_ref(int guess, int width, int height);
void	get_guesses_a(int guesses[4], char *input, int width, int height);
int		cmp_guesses(int guesses[4], char *input, int width, int height);
void	print_guess(int guess, int width, int height);
void	print_guesses(int guesses[4], int width, int height);

#endif