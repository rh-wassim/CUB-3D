/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:34:52 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 00:28:50 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Map with Walls");
	data->img.img = NULL;
}
