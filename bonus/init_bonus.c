/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:34:52 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 00:27:47 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	invalidtextures(t_data *data)
{
	if (!data->texture.north.img || !data->texture.south.img
		|| !data->texture.west.img || !data->texture.east.img)
	{
		printf("Error\nInvalid textures\n");
		exit(0);
	}
}

void	init_textures(t_data *data)
{
	int	i;

	data->texture.north.img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->n, &i, &i);
	data->texture.south.img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->s, &i, &i);
	data->texture.west.img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->w, &i, &i);
	data->texture.east.img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->e, &i, &i);
	invalidtextures(data);
	data->texture.north.addr = mlx_get_data_addr(data->texture.north.img,
			&data->texture.north.bits_per_pixel,
			&data->texture.north.line_length, &data->texture.north.endian);
	data->texture.south.addr = mlx_get_data_addr(data->texture.south.img,
			&data->texture.south.bits_per_pixel,
			&data->texture.south.line_length, &data->texture.south.endian);
	data->texture.west.addr = mlx_get_data_addr(data->texture.west.img,
			&data->texture.west.bits_per_pixel,
			&data->texture.west.line_length, &data->texture.west.endian);
	data->texture.east.addr = mlx_get_data_addr(data->texture.east.img,
			&data->texture.east.bits_per_pixel,
			&data->texture.east.line_length, &data->texture.east.endian);
}

void	door_textures(t_data *data)
{
	int	i;

	data->texture.door1.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door.xpm", &i, &i);
	data->texture.door2.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door2.xpm", &i, &i);
	data->texture.door3.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door3.xpm", &i, &i);
	if (!data->texture.door1.img || !data->texture.door2.img
		|| !data->texture.door3.img)
	{
		printf("Error\nInvalid textures\n");
		exit(0);
	}
	data->texture.door1.addr = mlx_get_data_addr(data->texture.door1.img,
			&data->texture.door1.bits_per_pixel,
			&data->texture.door1.line_length, &data->texture.door1.endian);
	data->texture.door2.addr = mlx_get_data_addr(data->texture.door2.img,
			&data->texture.door2.bits_per_pixel,
			&data->texture.door2.line_length, &data->texture.door2.endian);
	data->texture.door3.addr = mlx_get_data_addr(data->texture.door3.img,
			&data->texture.door3.bits_per_pixel,
			&data->texture.door3.line_length, &data->texture.door3.endian);
}

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
	ray->horizontallhitcontent = '0';
	ray->verticalhitcontent = '0';
	ray->wallhitcontent = '0';
}
