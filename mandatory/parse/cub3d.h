/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:31:51 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:15:37 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "../../libft/libft.h"

typedef struct s_pars
{
	char	*n;
	char	*e;
	char	*w;
	char	*s;
	int		f;
	int		c;
	char	**l_map;
	int		elem;
	int		nb_line;
	char	player;
	int		player_x;
	int		player_y;
	int		flag;
}	t_pars;

char	*get_texture(char *line);
char	*sk_sp(char *line);
int		check_map_char(char c);
int		check_player(char pl);
int		check_all_elem(t_pars *map);
int		check_tx_filled(t_pars *map);
int		check_colors_filled(t_pars *map);
int		set_colors(char *line);
int		check_wall(char *line);
void	ft_error(char *str);
void	validate_name(char *name);
void	ft_init(t_pars *map);
void	set_pars(char *file, t_pars *map);
void	p_pos(t_pars *map, int i, int j);
void	fill_colors(char *line, t_pars *map);
void	all_ele_fil(t_pars *map, char *line);
void	fill_textures(char *line, t_pars *map);
void	init_pars(char *line, t_pars *map);
void	free_double(char **line);
void	inside_map(t_pars *map);
int		size_l(char *line, int j);
void	fill_north_east(char *line, t_pars *map);
void	is_surrounded(t_pars *map, int i, int j);
void	check_textures(t_pars *map, char *line, int fd);
int		is_integer(const char *str);
int is_integer_with_max_length(const char *str, int max_length);
#endif
