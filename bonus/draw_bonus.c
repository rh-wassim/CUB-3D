/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:37:09 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/29 17:56:04 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"
#define MINI_MAP_SIZE 100
#define MINI_MAP_TILE_SIZE 8

void	draw_players(t_data *data);

void	draw_line(t_data *data, t_Point a, t_Point b, int color)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(&data->img, a.x, a.y, color);
		a.x += dx / (float)steps;
		a.y += dy / (float)steps;
		i++;
	}
}

void	draw_util(t_data *data, int x, int y, int color)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = x * 8;
	right = left + 8;
	top = y * 8;
	bottom = top + 8;
	while (left < right)
	{
		top = y * 8;
		while (top < bottom)
		{
			my_mlx_pixel_put(&data->img, left, top, color);
			top++;
		}
		left++;
	}
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map->nb_line)
	{
		x = 0;
		while (x < (int)ft_strlen(data->map->l_map[y]))
		{
			if (data->map->l_map[y][x] == '1')
				draw_util(data, x, y, 0x000000);
			else if (data->map->l_map[y][x] == 'D')
				draw_util(data, x, y, 0xFF0000);
			else if (data->map->l_map[y][x] == 'O')
				draw_util(data, x, y, 0xFFFFFF);
			else if (data->map->l_map[y][x] == '0')
				draw_util(data, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
	draw_player(data);
}

void	draw_player(t_data *data)
{
	t_Player	player;
	int			x;
	int			y;
	int			dx;
	int			dy;

	player = data->player;
	y = (int)player.position.y - PLAYER_RADIUS;
	y = y / 8;
	while (y <= (player.position.y + PLAYER_RADIUS) / 8)
	{
		x = (int)player.position.x - PLAYER_RADIUS;
		x = x / 8;
		while (x <= (player.position.x + PLAYER_RADIUS) / 8)
		{
			dx = x - player.position.x / 8;
			dy = y - player.position.y / 8;
			if (sqrt(dx * dx + dy * dy) <= PLAYER_RADIUS)
				my_mlx_pixel_put(&data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
