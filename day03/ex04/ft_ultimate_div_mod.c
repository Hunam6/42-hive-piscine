/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:05:50 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/12 11:10:25 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a_before;
	int	b_before;

	a_before = *a;
	b_before = *b;
	*a = a_before / b_before;
	*b = a_before % b_before;
}
