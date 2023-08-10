/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:46:21 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 20:59:15 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cast_ray(t_data *data, t_ray *ray)
{
	t_Point	b;

	b.x = data->player.position.x + ray->distance * cos(ray->rayangle);
	b.y = data->player.position.y + ray->distance * sin(ray->rayangle);
	if (b.x >= 0 && b.x <= WINDOW_WIDTH && b.y >= 0 && b.y <= WINDOW_HEIGHT)
		draw_line(data, data->player.position, b, 0x00FF00);
}

// Check if the new position is valid (not colliding with walls)
void	collide(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x / TILE_SIZE);
	map_y = (int)(new_y / TILE_SIZE);
	if (map_x >= 0 && map_y >= 0 && map_y < data->map->nb_line
		&& map_x < (int)(ft_strlen(data->map->l_map[map_y])))
	{
		if (data->map->l_map[map_y][map_x] != '1')
		{
			data->player.position.x = new_x;
			data->player.position.y = new_y;
		}
	}
}

void	compdistance(t_ray *ray)
{
	if (ray->horhitdistance < ray->verhitdistance)
	{
		ray->distance = ray->horhitdistance;
		ray->washithorizantal = true;
		ray->wallhitx = ray->horizontalhit.x;
		ray->wallhity = ray->horizontalhit.y;
	}
	else
	{
		ray->distance = ray->verhitdistance;
		ray->washithorizantal = false;
		ray->wallhitx = ray->verticalhit.x;
		ray->wallhity = ray->verticalhit.y;
	}
}

void	castallray(t_data *data)
{
	t_Player	player;
	double		rayangle;
	t_ray		ray;
	int			strip_id;

	strip_id = 0;
	player = data->player;
	rayangle = player.angle - (M_PI / 6);
	while (strip_id < WINDOW_WIDTH)
	{
		ray.rayangle = normalizeangle(rayangle);
		init_ray(&ray);
		horizontal(data, &ray, rayangle);
		vertical(data, &ray, rayangle);
		compdistance(&ray);
		generate3dprojection(data, &ray, strip_id);
		rayangle += (M_PI / 3) / WINDOW_WIDTH;
		strip_id++;
	}
}
