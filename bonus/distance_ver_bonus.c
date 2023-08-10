/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_ver_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:01:43 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 15:30:58 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	find_vertical_wall_helper(t_data *data, t_ray *ray)
{
	int	mx;
	int	my;

	mx = (int)(ray->xintercept) / TILE_SIZE;
	my = (int)(ray->yintercept) / TILE_SIZE;
	if (mx < 0 || my < 0 || my >= data->map->nb_line
		|| mx >= (int) ft_strlen(data->map->l_map[my]))
	{
		ray->verhitdistance = distancebetweenpoints(data->player.position.x,
				data->player.position.y, ray->xintercept, ray->yintercept);
		ray->verticalhit.x = ray->xintercept;
		ray->verticalhit.y = ray->yintercept;
		return (1);
	}
	if (data->map->l_map[my][mx] == '1' || data->map->l_map[my][mx] == 'D')
	{
		ray->verhitdistance = distancebetweenpoints(data->player.position.x,
				data->player.position.y, ray->xintercept, ray->yintercept);
		ray->verticalhit.x = ray->xintercept;
		ray->verticalhit.y = ray->yintercept;
		ray->verticalhitcontent = data->map->l_map[my][mx];
		return (1);
	}
	return (0);
}

void	init_vertival(t_data *data, t_ray *ray, double rayAngle)
{
	if (ray->israyfacingleft)
	{
		ray->xintercept = floor(data->player.position.x / TILE_SIZE)
			* TILE_SIZE - 0.01;
		ray->yintercept = data->player.position.y
			+ (ray->xintercept - data->player.position.x) * tan(rayAngle);
		ray->xstep = -TILE_SIZE;
		ray->ystep = ray->xstep * tan(rayAngle);
	}
	else
	{
		ray->xintercept = floor(data->player.position.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		ray->yintercept = data->player.position.y
			+ (ray->xintercept - data->player.position.x) * tan(rayAngle);
		ray->xstep = TILE_SIZE;
		ray->ystep = TILE_SIZE * tan(rayAngle);
	}
}

void	vertical(t_data *data, t_ray *ray, double rayAngle)
{
	init_vertival(data, ray, rayAngle);
	while (1)
	{
		if (find_vertical_wall_helper(data, ray))
			break ;
		else
		{
			check_if_any_open_doors(data, ray);
		}
	}
}
