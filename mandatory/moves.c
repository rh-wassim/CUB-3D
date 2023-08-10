/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:02 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 21:03:00 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	arrows(int key, t_data *data, double *new_x, double *new_y)
{
	if (key == KEY_UP)
	{
		*new_x += 10 * cos(data->player.angle);
		*new_y += 10 * sin(data->player.angle);
	}
	else if (key == KEY_DOWN)
	{
		*new_x -= 10 * cos(data->player.angle);
		*new_y -= 10 * sin(data->player.angle);
	}
	else if (key == KEY_RIGHT)
		data->player.angle += 0.1;
	else if (key == KEY_LEFT)
		data->player.angle -= 0.1;
}

void	ad(int key, t_data *data, double *new_x, double *new_y)
{
	if (key == KEY_A)
	{
		*new_x += 10 * cos(data->player.angle - M_PI_2);
		*new_y += 10 * sin(data->player.angle - M_PI_2);
	}
	else if (key == KEY_D)
	{
		*new_x += 10 * cos(data->player.angle + M_PI_2);
		*new_y += 10 * sin(data->player.angle + M_PI_2);
	}
	else if (key == KEY_W)
	{
		*new_x += 10 * cos(data->player.angle);
		*new_y += 10 * sin(data->player.angle);
	}
	else if (key == KEY_S)
	{
		*new_x -= 10 * cos(data->player.angle);
		*new_y -= 10 * sin(data->player.angle);
	}
}

int	key_handler(int key, t_data *data)
{
	double	new_x;
	double	new_y;

	if (key == 53)
		exit(0);
	new_x = data->player.position.x;
	new_y = data->player.position.y;
	if (key >= KEY_LEFT && key <= KEY_UP)
		arrows(key, data, &new_x, &new_y);
	if (key >= KEY_A && key <= KEY_W)
		ad(key, data, &new_x, &new_y);
	collide(data, new_x, new_y);
	return (0);
}
