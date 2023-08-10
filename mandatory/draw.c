/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:37:09 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 00:28:33 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
