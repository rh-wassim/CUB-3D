/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:35:42 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:15:57 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_colors_filled(t_pars *map)
{
	if (map->f && map->c)
		return (1);
	return (0);
}

int	check_tx_filled(t_pars *map)
{
	if (map->n && map->e && map->w && map->s)
		return (1);
	return (0);
}

int	check_all_elem(t_pars *map)
{
	if (map->n && map->e && map->w && map->s && map->f && map->c)
		return (1);
	return (0);
}

int	check_player(char pl)
{
	if (pl == 'N' || pl == 'E' || pl == 'W' || pl == 'S')
		return (1);
	return (0);
}

int	check_map_char(char c)
{
	if (check_player(c) || c == ' ' || c == '0' || c == '1')
		return (1);
	return (0);
}
