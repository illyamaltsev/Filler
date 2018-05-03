/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorinm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:33:14 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/23 18:33:17 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_position(t_filler param, int x, int y)
{
	int i;
	int j;
	int t_x;
	int count;
	int point;

	point = 0;
	count = 0;
	i = -1;
	t_x = x - 1;
	while ((x = t_x) == t_x && param.token[++i] != NULL && param.map[y] != NULL)
	{
		j = -1;
		while (param.token[i][++j] != '\0' && param.map[y][++x] != '\0')
		{
			if (param.token[i][j] == '*' && param.map[y][x] == param.ally)
				count++;
			if (param.token[i][j] == '*' && param.map[y][x] == param.enemy)
				point++;
		}
		y++;
	}
	if (count == 1 && point == 0)
		return (1);
	return (0);
}

int	**put_new_variant(int **arr, int *str)
{
	int	i;
	int **new_arr;

	if (arr == NULL)
	{
		new_arr = malloc(sizeof(new_arr) * (1 + 1));
		new_arr[0] = str;
		new_arr[1] = NULL;
	}
	else
	{
		i = 0;
		while (arr[i] != NULL)
			i++;
		new_arr = malloc(sizeof(new_arr) * (i + 2));
		i = -1;
		while (arr[++i] != NULL)
			new_arr[i] = arr[i];
		new_arr[i] = str;
		new_arr[i + 1] = NULL;
	}
	free(arr);
	return (new_arr);
}

int	**find_variants(t_filler *param)
{
	int **variants;
	int x;
	int y;

	y = 0;
	variants = NULL;
	while (y + param->y1 - 1 < param->y)
	{
		x = 0;
		while (x + param->x1 - 1 < param->x)
		{
			if (check_position(*param, x, y))
				variants = put_new_variant(variants, put_3_ints(x, y, '\0'));
			x++;
		}
		y++;
	}
	if (variants == NULL)
		variants = put_new_variant(variants, put_3_ints(0, 0, -1));
	return (variants);
}

int	*algoritm(t_filler param)
{
	int	**variants;
	int	*res;
	int *tmp;
	int i;

	variants = find_variants(&param);
	tmp = find_res(param, variants);
	res = put_3_ints(tmp[0], tmp[1], tmp[2]);
	i = 0;
	while (variants[i] != NULL)
		free(variants[i++]);
	free(variants);
	return (res);
}
