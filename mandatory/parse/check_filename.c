/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:35:54 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:23:08 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void validate_name(char *name)
{
    int len = ft_strlen(name);
    
    if (len < 4 || ft_strcmp(name + len - 4, ".cub") != 0)
        ft_error("Invalid scene file extension. Expected .cub file.");
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

int is_integer_with_max_length(const char *str, int max_length)
{
    if (*str == '\0')
        return 0;

    if (ft_strlen(str) > max_length)
        return 0;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}