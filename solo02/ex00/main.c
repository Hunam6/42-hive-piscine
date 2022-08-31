/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:07:33 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/28 19:58:53 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include "ft_btree.h"

int	is_num(char ch)
{
	return (('0' <= ch && ch <= '9') || ch == '-');
}

int	is_op(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int	ft_atoi(char *str)
{
	int	res;
	int	idx;
	int	is_pos;

	if (!(str[0] == '-' || str[0] == '+' || is_num(str[0])))
		return (0);
	res = 0;
	idx = 0;
	if (str[0] == '-')
	{
		idx++;
		is_pos = 0;
	}
	if (str[0] == '+')
		idx++;
	while (str[idx] != '\0')
	{
		if (!is_num(str[idx]))
			break ;
		res = res * 10 + (str[idx] - 48);
		idx++;
	}
	if (is_pos)
		return (res);
	return (-res);
}

int	get_corresponding_paren(char *str, int i_first)
{
	int	layer;

	layer = 1;
	i_first++;
	while (layer != 0 && str[i_first])
	{
		if (str[i_first] == '(')
			layer++;
		if (str[i_first] == ')')
			layer--;
		i_first++;
	}
	return (i_first);
}

int	get_next_not_nb(char *str, int i_start)
{
	while (!is_num(str[i_start]) && str[i_start])
		i_start++;
	return (i_start);
}

void	handle_priority(char *str, int *paren, int i_start, int prev_nb)
{
	paren[0] = prev_nb - 1;
	if (str[i_start + 2] == '(')
		paren[1] = get_corresponding_paren(str, i_start + 2);
	else
		paren[1] = get_next_not_nb(str, i_start + 2);
}

int	**get_parenthesis(char *str)
{
	int	i;
	int	prev_nb;
	int	**parenthesis;
	int	parenthesis_i;

	i = 0;
	prev_nb = 0;
	parenthesis = malloc(sizeof(int *) * ft_strlen(str));
	parenthesis_i = 0;
	while (str[i])
	{
		if (is_num(str[i]) && str[i - 1] == ' ')
			prev_nb = i;
		else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			parenthesis[parenthesis_i] = malloc(sizeof(int) * 2);
			handle_priority(str, parenthesis[parenthesis_i++], i, prev_nb);
		}
		else if (str[i] == '(')
		{
			parenthesis[parenthesis_i] = malloc(sizeof(int) * 2);
			parenthesis[parenthesis_i][0] = i;
			parenthesis[parenthesis_i++][1] = get_corresponding_paren(str, i);
		}
		i++;
	}
	return (parenthesis);
}

char	*cut_str(char *str, int beg, int end)
{
	int		i;
	int		j;
	char	*out;

	i = beg;
	j = 0;
	out = malloc(sizeof(char) * end - beg);
	while (i < end)
		out[j++] = str[i++];
	out[j] = '\0';
	return (out);
}

t_btree	*get_tree(char *str, int **parenthesis, t_btree	*tree)
{
	int		i;
	char	num[12];
	int		num_i;

	i = 0;
	num_i = 0;
	while (!is_op(str[i]) && str[i])
	{
		if (is_num(str[i]))
			num[num_i++] = str[i];
		i++;
	}
	if (str[i])
	{
		tree = new_node((void *) str[i]);
		tree->left = get_tree(&str[i + 1], parenthesis, tree->left);
		tree->right = get_tree(&str[i + 1], parenthesis, tree->right);
	}
	return (tree);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}

void	print(void *item)
{
	printf("%d\n", (int) item);
}

int	eval_expr(char *str)
{
	int		**parenthesis;
	t_btree	*tree;

	parenthesis = get_parenthesis(str);
	printf("%d, %d\n", parenthesis[0][0], parenthesis[0][1]);
	printf("%d, %d\n", parenthesis[1][0], parenthesis[1][1]);
	printf("%d, %d\n", parenthesis[2][0], parenthesis[2][1]);
	printf("%d, %d\n", parenthesis[3][0], parenthesis[3][1]);
	tree = NULL;
	tree = get_tree(str, parenthesis, tree);
	btree_apply_prefix(tree, print);
	return (-1);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}