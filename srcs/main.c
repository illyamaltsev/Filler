/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:59:29 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/14 11:59:30 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_player(char *line, t_filler *param)
{
	while (*line != 'p')
		line++;
	line++;
	param->player = ft_atoi(line);
	param->ally = 'O';
	param->enemy = 'X';
	if (param->player == 2)
	{
		param->ally = 'X';
		param->enemy = 'O';
	}
	param->check_player = 0;
}

void	param_free(t_filler *param)
{
	param->x = 0;
	param->y = 0;
	param->y1 = 0;
	param->x1 = 0;
	param->i = 0;
	param->j = 0;
	free_arr(param->token);
	free(param->token);
	free_arr(param->map);
	free(param->map);
}

int		main(void)
{
	int			*koord;
	char		*line;
	t_filler	param;

	get_next_line(0, &line);
	find_player(line, &param);
	ft_strdel(&line);
	param.token = NULL;
	param.map = NULL;
	param.change = 0;
	while (1)
	{
		parsing(&line, &param);
		corect(&param);
		koord = algoritm(param);
		ft_printf("%d %d\n", koord[1] - param.i, koord[0] - param.j);
		param_free(&param);
		free(koord);
		if (koord[2] == -1)
			break ;
	}
	return (0);
}
