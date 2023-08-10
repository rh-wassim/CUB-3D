/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:45:28 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/29 17:40:22 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	rotation_with_mosue(int x, int y, t_data *data)
{
	(void)y;
	if (data->player.mouse_rotation < x)
		data->player.angle += 0.1;
	else if (data->player.mouse_rotation > x)
		data->player.angle -= 0.1;
	data->player.mouse_rotation = x;
	if (data->player.mouse_rotation > WINDOW_WIDTH
		|| data->player.mouse_rotation < 0)
		mlx_mouse_move(data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_hide();
	return (0);
}

void	init_parse(t_data *data, char **av)
{
	data->img.img = NULL;
	data->map = malloc(sizeof(t_pars));
	validate_name(av[1]);
	ft_init(data->map);
	set_pars(av[1], data->map);
	if (!check_colors_filled(data->map) || !check_tx_filled(data->map))
		ft_error("Elements not filled");
	inside_map(data->map);
}

t_data	*init_data(char **av)
{
	t_data	*data;
	int		x;
	int		y;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_parse(data, av);
	x = data->map->player_x;
	y = data->map->player_y;
	data->player.mouse_rotation = 0;
	data->player.position.x = (y * TILE_SIZE + TILE_SIZE / 2);
	data->player.position.y = (x * TILE_SIZE + TILE_SIZE / 2);
	data->player.angle = player_angle(data->map->player);
	data->map->l_map[x][y] = '0';
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	init_textures(data);
	door_textures(data);
	data->action_close = false;
	data->action_open = false;
	data->texture.currentdoorframe = &data->texture.door1;
	return (data);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_error("Wrong number of arguments!");
	data = init_data(av);
	data->show_mini_map = true;
	mlx_hook(data->win_ptr, 6, 0, rotation_with_mosue, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_handler, data);
	mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
