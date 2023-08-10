/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:35:54 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/28 00:27:17 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	validate_name(char *name)
{
	if (ft_strchr(name, '.'))
	{
		if (ft_strncmp(ft_strrchr(name, '.'), ".cub", 4))
			ft_error("Invalid scene file extension. Expected .cub file.\n");
	}
}

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

void	ft_init(t_pars *map)
{
	map->l_map = NULL;
	map->n = NULL;
	map->e = NULL;
	map->w = NULL;
	map->s = NULL;
	map->f = 0;
	map->c = 0;
	map->elem = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->player = '\0';
	map->nb_line = 0;
	map->flag = -1;
}
