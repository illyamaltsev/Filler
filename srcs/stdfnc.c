/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfnc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:26:07 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/21 14:26:08 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define ABC(x) (((x) > 0) ? (x) : -(x))

int		*choose_closest_variant(int x, int y, int **var, t_filler param)
{
	int i;
	int k;
	int min_distance;

	i = 0;
	k = 0;
	min_distance = param.y + param.x;
	while (var[i] != NULL)
	{
		if (ABC((var[i][0] - x)) + ABC((var[i][1] - y)) < min_distance)
		{
			min_distance = ABC((var[i][0] - x)) + ABC((var[i][1] - y));
			k = i;
		}
		i++;
	}
	return (var[k]);
}

int		*put_3_ints(int c1, int c2, int c3)
{
	int *new;

	new = malloc(sizeof(int) * 3);
	new[0] = c1;
	new[1] = c2;
	new[2] = c3;
	return (new);
}

void	pass_line(char **line)
{
	get_next_line(0, line);
	ft_strdel(line);
}

void	print_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		dprintf(2, "%s\n", arr[i]);
		i++;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}
