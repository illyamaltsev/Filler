/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:28:44 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/21 14:28:45 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_str_fromchars(char *str, char c1, char c2)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c1 && str[i] != c2)
			return (0);
		i++;
	}
	return (1);
}

int		is_line_fromchars(char **arr, char c1, char c2, int j)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i][j] != c1 && arr[i][j] != c2)
			return (0);
		i++;
	}
	return (1);
}

void	find_token_start(t_filler *param)
{
	param->i = 0;
	while (is_str_fromchars(param->token[param->i], '.', 0))
		param->i++;
	param->j = 0;
	while (is_line_fromchars(param->token, '.', 0, param->j))
		param->j++;
}

void	cut_token(t_filler *param)
{
	int		i;
	int		k;
	int		end_i;
	int		end_j;
	char	**new_arr;

	end_j = param->x1 - 1;
	end_i = param->y1 - 1;
	while (is_str_fromchars(param->token[end_i], '.', 0))
		end_i--;
	end_i++;
	while (is_line_fromchars(param->token, '.', 0, end_j))
		end_j--;
	end_j++;
	new_arr = (char **)malloc(sizeof(new_arr) * (end_i - param->i + 1));
	param->x1 = end_j - param->j;
	param->y1 = end_i - param->i;
	i = 0;
	k = param->i;
	while (i < end_i - param->i)
		new_arr[i++] = ft_strsub(param->token[k++], param->j, end_j - param->j);
	new_arr[i] = NULL;
	free_arr(param->token);
	free(param->token);
	param->token = new_arr;
}

void	corect(t_filler *param)
{
	find_token_start(param);
	cut_token(param);
}
