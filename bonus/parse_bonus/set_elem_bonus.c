/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:15:11 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:23:49 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*get_texture(char *line)
{
	char	*result;
	char	**sp;
	int		fd;

	sp = ft_split(line, ' ');
	if (!sp || !sp[1] || sp[2])
		ft_error("something wrong with texture");
	result = ft_strdup(sp[1]);
	free_double(sp);
	fd = open(result, O_RDONLY);
	if (fd == -1)
		ft_error("textere file not found!");
	return (result);
}

void	fill_textures(char *line, t_pars *map)
{
	if (ft_strncmp("SO ", line, 3) == 0)
	{
		if (!map->s)
			map->s = get_texture(line);
		else
			ft_error("duplicat sumbol!");
		map->elem++;
	}
	if (ft_strncmp("WE ", line, 3) == 0)
	{
		if (!map->w)
			map->w = get_texture(line);
		else
			ft_error("duplicat sumbol!");
		map->elem++;
	}
	else
		fill_north_east(line, map);
}

void	fill_colors(char *line, t_pars *map)
{
	if (ft_strncmp("F ", line, 2) == 0)
	{
		if (map->f)
			ft_error("the element has already filled 1");
		map->f = set_colors(line);
		map->elem++;
	}
	if (ft_strncmp("C ", line, 2) == 0)
	{
		if (!map->c)
		{
			map->c = set_colors(line);
			map->elem++;
		}
		else
			ft_error("the element has already filled 2");
	}
}

void	init_pars(char *line, t_pars *map)
{
	static int	i;

	if (i < map->nb_line)
	{
		map->l_map[i] = ft_strdup(line);
		i++;
	}
	if (i == map->nb_line)
		map->l_map[i] = NULL;
}

void	all_ele_fil(t_pars *map, char *line)
{
	if (line[0] == ' ' && !check_all_elem(map) && !map->l_map[0])
		line = sk_sp(line);
	if (!line[0])
		return ;
	if (!check_tx_filled(map))
		fill_textures(line, map);
	if (!check_colors_filled(map))
		fill_colors(line, map);
	else if (check_all_elem(map))
	{
		if (!line[0])
			return ;
		if (!check_map_char(line[0]))
			ft_error("Wrong element in the file");
		init_pars(line, map);
	}
}
