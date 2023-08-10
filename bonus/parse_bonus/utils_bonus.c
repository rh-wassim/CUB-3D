/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:15:24 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:23:53 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	fill_north_east(char *line, t_pars *map)
{
	if (ft_strncmp("NO ", line, 3) == 0)
	{
		if (!map->n)
			map->n = get_texture(line);
		else
			ft_error("duplicat sumbol!");
		map->elem++;
	}
	if (ft_strncmp("EA ", line, 3) == 0)
	{
		if (!map->e)
			map->e = get_texture(line);
		else
			ft_error("duplicat sumbol!");
		map->elem++;
	}
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	p_pos(t_pars *map, int i, int j)
{
	map->player_x = i;
	map->player_y = j;
	map->player = map->l_map[i][j];
}

int	size_l(char *line, int j)
{
	if (j > ft_strlen(line) - 1)
		return (1);
	return (0);
}

char	*sk_sp(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (line + i);
		i++;
	}
	return (line);
}
