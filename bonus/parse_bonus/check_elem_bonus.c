/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:35:42 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/28 14:12:56 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (check_player(c) || c == ' ' || c == '0' || c == '1' || c == 'D')
		return (1);
	return (0);
}
