/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:49:09 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 15:10:57 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//int	close_window(t_data *data)
//{
//	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//	exit(0);
//}
//
//void	initplayerpos(t_data *data, int x, int y)
//{
//	data->player.position.x = (y * TILE_SIZE + TILE_SIZE / 2);
//	data->player.position.y = (x * TILE_SIZE + TILE_SIZE / 2);
//	data->player.angle = player_angle(data->map->player);
//	data->map->l_map[x][y] = '0';
//}

void	init_parse(t_data *data, char **av)
{
	data->img.img = NULL;
	data->map = malloc(sizeof(t_pars));
	ft_init(data->map);
	validate_name(av[1]);
	set_pars(av[1], data->map);
	if (!check_colors_filled(data->map) || !check_tx_filled(data->map))
		ft_error("Elements not filled");
	inside_map(data->map);
}

//α(radians) = α(degrees) × π / 180° 0 in radians
int	main(int ac, char **av)
{
	t_data	*data;
	//int		x;
	//int		y;

	(void)ac;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	init_parse(data, av);
	//init_data(data);
	//init_textures(data);
	//x = data->map->player_x;
	//y = data->map->player_y;
	//initplayerpos(data, x, y);
	//mlx_hook(data->win_ptr, 2, 1L << 0, key_handler, data);
	//mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	//mlx_hook(data->win_ptr, 17, 1L << 17, &close_window, data);
	//mlx_loop(data->mlx_ptr);
	return (0);
}
