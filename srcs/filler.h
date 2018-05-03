/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:16:29 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/21 11:16:30 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/mylibft.h"

typedef struct		s_filler
{
	int				player;
	int				check_player;
	int				change;
	char			enemy;
	char			ally;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				i;
	int				j;
	char			**map;
	char			**token;
}					t_filler;

typedef struct		s_situation
{
	int				up;
	int				down;
	int				left;
	int				right;
}					t_situation;

void				parsing(char **line, t_filler *param);
void				corect(t_filler *param);
int					is_line_fromchars(char **arr, char c1, char c2, int j);
int					is_str_fromchars(char *str, char c1, char c2);
void				pass_line(char **line);
void				free_arr(char **arr);
void				print_arr(char **arr);
int					*put_3_ints(int c1, int c2, int c3);
int					*choose_closest_variant(int x, int y,
					int **var, t_filler param);
int					*algoritm(t_filler param);
int					*find_res(t_filler param, int **variants);

#endif
