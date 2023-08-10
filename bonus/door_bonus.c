/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:00:03 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/27 22:43:42 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	on_open(t_data *data, int *j)
{
	if (*j < 5)
		data->texture.currentdoorframe = &data->texture.door2;
	else if (*j < 10)
		data->texture.currentdoorframe = &data->texture.door3;
	else if (*j < 15)
	{
		data->texture.currentdoorframe = &data->texture.door1;
		data->action_open = false;
		data->map->l_map[data->door.y][data->door.x] = 'O';
		*j = 0;
	}
	*j = *j + 1;
}

void	on_close(t_data *data, int *i)
{
	data->map->l_map[data->door.y][data->door.x] = 'D';
	if (*i < 5)
		data->texture.currentdoorframe = &data->texture.door3;
	else if (*i < 10)
		data->texture.currentdoorframe = &data->texture.door2;
	else if (*i < 15)
	{
		data->texture.currentdoorframe = &data->texture.door1;
		data->action_close = false;
		*i = 0;
	}
	*i = *i + 1;
}

void	open_close(t_data *data)
{
	static int	i;
	static int	j;

	if (data->action_open)
		on_open(data, &j);
	if (data->action_close)
		on_close(data, &i);
}
