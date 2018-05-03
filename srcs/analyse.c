/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:12:52 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/26 13:12:53 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_situation		analise_enemy_situation(t_filler param)
{
	t_situation	enemy;

	enemy.up = 0;
	enemy.down = param.y - 1;
	enemy.left = 0;
	enemy.right = param.x - 1;
	while (is_str_fromchars(param.map[enemy.up], '.', param.ally))
		enemy.up++;
	while (is_line_fromchars(param.map, '.', param.ally, enemy.left))
		enemy.left++;
	while (is_str_fromchars(param.map[enemy.down], '.', param.ally))
		enemy.down--;
	while (is_line_fromchars(param.map, '.', param.ally, enemy.right))
		enemy.right--;
	return (enemy);
}

t_situation		analise_ally_situation(t_filler param)
{
	t_situation ally;

	ally.up = 0;
	ally.down = 0;
	ally.left = 0;
	ally.right = 0;
	if (!is_str_fromchars(param.map[0], '.', param.enemy))
		ally.up = 1;
	if (!is_line_fromchars(param.map, '.', param.enemy, 0))
		ally.left = 1;
	if (!is_str_fromchars(param.map[param.y - 1], '.', param.enemy))
		ally.down = 1;
	if (!is_line_fromchars(param.map, '.', param.enemy, param.x - 1))
		ally.right = 1;
	return (ally);
}

int				*move_right(t_filler param, t_situation enemy, int **variants)
{
	if (enemy.right + 2 < param.x - 2)
		return (choose_closest_variant(enemy.right + 2,
			enemy.up - 2, variants, param));
	else if (enemy.right + 1 < param.x - 2)
		return (choose_closest_variant(enemy.right + 1,
			enemy.up - 1, variants, param));
	else
		return (choose_closest_variant(enemy.right,
			enemy.up, variants, param));
}

int				*move_left(t_filler param, t_situation enemy, int **variants)
{
	if (enemy.down + 2 < param.y - 2)
		return (choose_closest_variant(enemy.left - 2,
			enemy.down + 2, variants, param));
	else if (enemy.down + 1 < param.y - 2)
		return (choose_closest_variant(enemy.left - 1,
			enemy.down + 1, variants, param));
	else
		return (choose_closest_variant(enemy.left,
			enemy.down, variants, param));
}

int				*find_res(t_filler param, int **variants)
{
	t_situation	enemy;
	t_situation	ally;

	enemy = analise_enemy_situation(param);
	ally = analise_ally_situation(param);
	if ((!ally.right && !ally.up) || (!ally.left && !ally.down))
	{
		if (!ally.left && !ally.down && param.change)
			return (move_left(param, enemy, variants));
		else if (!ally.right && !ally.up)
			return (move_right(param, enemy, variants));
		else if (!ally.left && !ally.down)
			return (move_left(param, enemy, variants));
	}
	else
	{
		if ((param.ally == 'X' && !param.change)
			|| (param.ally == 'O' && param.change))
			return (choose_closest_variant(0, 0, variants, param));
		if ((param.ally == 'O' && !param.change)
			|| (param.ally == 'X' && param.change))
			return (choose_closest_variant(param.x - 1, param.y - 1,
				variants, param));
	}
	return (0);
}
