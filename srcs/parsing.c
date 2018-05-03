/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:15:58 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/21 11:16:00 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*cpy_line(char *str, int i)
{
	int		j;
	char	*new;

	j = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		new[j] = str[i];
		i++;
		j++;
	}
	return (new);
}

char	**pars_arr(int y, int pos)
{
	char	*line;
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char*) * (y + 1));
	arr[y] = NULL;
	while (i < y)
	{
		get_next_line(0, &line);
		arr[i] = cpy_line(line, pos);
		ft_strdel(&line);
		i++;
	}
	return (arr);
}

void	find_x_y(t_filler *param, char **line_f, int point)
{
	char *line;

	get_next_line(0, line_f);
	line = *line_f;
	while (*line != ' ')
		line++;
	line++;
	if (point == 0)
	{
		param->y = ft_atoi(line);
		while (*line != ' ')
			line++;
		line++;
		param->x = ft_atoi(line);
	}
	else
	{
		param->y1 = ft_atoi(line);
		while (*line != ' ')
			line++;
		line++;
		param->x1 = ft_atoi(line);
	}
	ft_strdel(line_f);
}

int		first_player(char c, char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == c)
				return (1);
			if (arr[i][j] != c && arr[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

void	parsing(char **line, t_filler *param)
{
	find_x_y(param, line, 0);
	pass_line(line);
	param->map = pars_arr(param->y, 4);
	find_x_y(param, line, 1);
	param->token = pars_arr(param->y1, 0);
	if (param->check_player == 0 && first_player('X', param->map))
		param->change = 1;
	param->check_player = 1;
}
