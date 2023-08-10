/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_hor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:55:55 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 15:29:28 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	find_horizontal_wall_helper(t_data *data, t_ray *ray)
{
	int	mx;
	int	my;

	mx = (int)(ray->xintercept) / TILE_SIZE;
	my = (int)(ray->yintercept) / TILE_SIZE;
	if (mx < 0 || my < 0 || my >= data->map->nb_line
		|| mx >= (int) ft_strlen(data->map->l_map[my]))
	{
		ray->horhitdistance = distancebetweenpoints(data->player.position.x,
				data->player.position.y, ray->xintercept, ray->yintercept);
		ray->horizontalhit.x = ray->xintercept;
		ray->horizontalhit.y = ray->yintercept;
		return (1);
	}
	if (data->map->l_map[my][mx] == '1')
	{
		ray->horhitdistance = distancebetweenpoints(data->player.position.x,
				data->player.position.y, ray->xintercept, ray->yintercept);
		ray->horizontalhit.x = ray->xintercept;
		ray->horizontalhit.y = ray->yintercept;
		return (1);
	}
	return (0);
}

void	init_horizantal(t_data *data, t_ray *ray, double rayAngle)
{
	if (ray->israyfacingup)
	{
		ray->yintercept = floor(data->player.position.y / TILE_SIZE)
			* TILE_SIZE - 0.1;
		ray->xintercept = data->player.position.x
			+ (ray->yintercept - data->player.position.y) / tan(rayAngle);
		ray->ystep = -TILE_SIZE;
		ray->xstep = ray->ystep / tan(rayAngle);
	}
	else
	{
		ray->yintercept = floor(data->player.position.y / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		ray->xintercept = data->player.position.x
			+ (ray->yintercept - data->player.position.y) / tan(rayAngle);
		ray->ystep = TILE_SIZE;
		ray->xstep = ray->ystep / tan(rayAngle);
	}
}

void	horizontal(t_data *data, t_ray *ray, double rayAngle)
{
	init_horizantal(data, ray, rayAngle);
	while (1)
	{
		if (find_horizontal_wall_helper(data, ray))
			break ;
		else
		{
			ray->xintercept += ray->xstep;
			ray->yintercept += ray->ystep;
		}
	}
}
