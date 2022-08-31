/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:21:00 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/27 21:28:19 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H
# define FT_HELPERS_H

# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	putstr(char *str);
void	putch(char ch);
void	putnb(int nb);

#endif