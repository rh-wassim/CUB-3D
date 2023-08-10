/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:18:40 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 20:57:04 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_ray(t_ray *ray)
{
	ray->washitvertical = false;
	if (ray->rayangle < M_PI_2 || ray->rayangle > 3 * M_PI_2)
		ray->israyfacingright = true;
	else
		ray->israyfacingright = false;
	ray->israyfacingleft = !ray->israyfacingright;
	if (ray->rayangle > 0 && ray->rayangle < M_PI)
		ray->israyfacingdown = true;
	else
		ray->israyfacingdown = false;
	ray->israyfacingup = !ray->israyfacingdown;
	ray->horhitdistance = INT_MAX;
	ray->verhitdistance = INT_MAX;
}

void	init_projection(t_data *data, t_ray *ray)
{
	float	angle;

	angle = ray->rayangle - data->player.angle;
	data->projection.prepdistance = ray->distance
		* cos(normalizeangle(angle));
	data->projection.distanceprojplane = (WINDOW_WIDTH / 2)
		/ tan((M_PI / 6));
	data->projection.projectedwallheight
		= (TILE_SIZE / data->projection.prepdistance)
		* data->projection.distanceprojplane;
	data->projection.wallstripheight
		= (int)data->projection.projectedwallheight;
	data->projection.walltoppixel = (WINDOW_HEIGHT / 2)
		- (data->projection.wallstripheight / 2);
	if (data->projection.walltoppixel < 0)
		data->projection.walltoppixel = 0;
	data->projection.wallbottompixel = (WINDOW_HEIGHT / 2)
		+ (data->projection.wallstripheight / 2);
	if (data->projection.wallbottompixel > WINDOW_HEIGHT)
		data->projection.wallbottompixel = WINDOW_HEIGHT;
}

void	init_wall(t_data *data, t_ray *ray)
{
	if (ray->washithorizantal)
	{
		data->projection.textureoffsetx = (int)ray->wallhitx % TILE_SIZE;
		if (ray->israyfacingup)
			data->projection.img = &data->texture.south;
		else
			data->projection.img = &data->texture.north;
	}
	else
	{
		data->projection.textureoffsetx = (int)ray->wallhity % TILE_SIZE;
		if (ray->israyfacingleft)
			data->projection.img = &data->texture.west;
		else
			data->projection.img = &data->texture.east;
	}
}

void	wall_projection(t_data *data, int i)
{
	t_Point			a;
	t_Point			b;
	int				y;
	int				d;
	unsigned int	color;

	a.x = i;
	a.y = data->projection.walltoppixel;
	b.x = i;
	b.y = data->projection.wallbottompixel;
	y = data->projection.walltoppixel;
	while (y < data->projection.wallbottompixel)
	{
		d = y + (data->projection.wallstripheight / 2)
			- (WINDOW_HEIGHT / 2);
		data->projection.textureoffsety = d * ((float)TILE_SIZE
				/ data->projection.wallstripheight);
		color = my_mlx_get_color(data->projection.img,
				data->projection.textureoffsetx,
				data->projection.textureoffsety);
		my_mlx_pixel_put(&data->img, i, y, color);
		y++;
	}
}

void	generate3dprojection(t_data *data, t_ray *ray, int i)
{
	t_Point	a;
	t_Point	b;

	init_projection(data, ray);
	a.x = i;
	a.y = 0;
	b.x = i;
	b.y = data->projection.walltoppixel;
	draw_line(data, a, b, data->map->c);
	init_wall(data, ray);
	wall_projection(data, i);
	a.x = i;
	a.y = data->projection.wallbottompixel;
	b.x = i;
	b.y = WINDOW_HEIGHT;
	draw_line(data, a, b, data->map->f);
}
