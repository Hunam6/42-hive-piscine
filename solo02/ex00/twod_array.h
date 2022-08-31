/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twod_array.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:00:10 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 12:31:40 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWOD_ARRAY_H
# define TWOD_ARRAY_H

typedef struct s_2d_array
{
	int	**data;
	int	len;
} t_2d_array;

t_2d_array	*init(int size);
void		append(int nb);
int			get(int i);

#endif