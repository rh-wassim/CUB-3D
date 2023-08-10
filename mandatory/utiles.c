/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:25:37 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 21:03:07 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	normalizeangle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	distancebetweenpoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	player_angle(char p)
{
	if (p == 'E')
		return (0);
	if (p == 'N')
		return (3 * M_PI_2);
	if (p == 'S')
		return (M_PI_2);
	if (p == 'W')
		return (M_PI);
	return (M_PI);
}
