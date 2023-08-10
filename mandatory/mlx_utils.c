/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:10:17 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 20:52:36 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	render_next_frame(t_data *data)
{
	if (data->img.img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	castallray(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

void	projectionimg(t_data *data, t_ray *ray)
{
	int	y;
	int	color;
	int	d;

	y = data->projection.walltoppixel;
	while (y < data->projection.wallbottompixel)
	{
		d = y + (data->projection.wallstripheight / 2) - (WINDOW_HEIGHT / 2);
		data->projection.textureoffsety = d
			* ((float)TILE_SIZE / data->projection.wallstripheight);
		color = my_mlx_get_color(data->projection.img,
				data->projection.textureoffsetx,
				data->projection.textureoffsety);
		my_mlx_pixel_put(&data->img, ray->rayangle, y, color);
		y++;
	}
}
