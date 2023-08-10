/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:50:36 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:16:16 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_surrounded(t_pars *map, int i, int j)
{
	if ((map->l_map[i][j] == '0' || check_player(map->l_map[i][j]))
		&& (i == 0 || j == 0 || map->l_map[i][j + 1] == '\0'
		|| map->l_map[i + 1] == NULL
		|| map->l_map[i][j + 1] == ' ' || map->l_map[i][j - 1] == ' '
		|| size_l(map->l_map[i - 1], j) || size_l(map->l_map[i + 1], j)
		|| map->l_map[i + 1][j] == ' ' || map->l_map[i - 1][j] == ' '))
		ft_error("map_error");
	if (!check_map_char(map->l_map[i][j]))
		ft_error("There is a foreign charachter!");
}

void	inside_map(t_pars *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->l_map[i])
	{
		j = 0;
		while (map->l_map[i][j])
		{
			is_surrounded(map, i, j);
			if (check_player(map->l_map[i][j]))
			{
				if (map->player == '\0')
					p_pos(map, i, j);
				else
					ft_error("Find more than 1 player!");
			}
			j++;
		}
		i++;
	}
	if (map->player == '\0')
		ft_error("No player found!");
}

void	check_textures(t_pars *map, char *line, int fd)
{
	while (line)
	{
		all_ele_fil(map, line);
		free(line);
		line = get_next_line(fd);
	}
}

int is_integer(const char *str)
{
    if (*str == '\0')
        return 0;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}