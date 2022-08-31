/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:12:46 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/18 18:53:25 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int	ft_button(int i, int j, int k)
{
	int	arr[3];

	*arr = i;
	*(arr + 1) = j;
	*(arr + 2) = k;
	if (arr[1] < arr[0])
		swap(&arr[1], &arr[0]);
	if (arr[2] < arr[1])
		swap(&arr[2], &arr[1]);
	if (arr[1] < arr[0])
		swap(&arr[1], &arr[0]);
	return (arr[1]);
}
