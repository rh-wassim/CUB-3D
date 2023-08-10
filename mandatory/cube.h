/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:01:19 by ofrikel           #+#    #+#             */
/*   Updated: 2023/07/28 00:26:53 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include "parse/cub3d.h"
//# include "mlx.h"
# include <float.h>

# define MAP_WIDTH 25
# define MAP_HEIGHT 15
# define PLAYER_RADIUS 10
# define TILE_SIZE 64

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600

# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_door {
	int		x;
	int		y;
	int		isopen;
	int		nearbydoor;
	double	distance;
}	t_door;

typedef struct s_point{
	double	x;
	double	y;
}	t_Point;

typedef struct s_player{
	t_Point	position;
	double	angle;
	float	width;
	float	height;

}	t_Player;

typedef struct s_texture {
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	*currentdoorframe;
	t_img	door1;
	t_img	door2;
	t_img	door3;
}	t_texture;

typedef struct s_projection
{
	float	prepdistance;
	float	distanceprojplane;
	float	projectedwallheight;
	int		wallstripheight;
	int		walltoppixel;
	int		wallbottompixel;
	int		textureoffsetx ;
	int		textureoffsety ;
	t_img	*img;
}	t_projection;

typedef struct s_data{
	t_Player			player;
	void				*mlx_ptr;
	void				*win_ptr;
	int					map_width;
	int					map_height;
	int					action_open;
	int					action_close;
	t_pars				*map;
	t_projection		projection;
	t_img				img;
	t_texture			texture;
	t_door				door;
	int					show_mini_map;
}	t_data;

typedef struct s_ray {
	float	rayangle;
	double	wallhitx;
	double	wallhity;
	double	distance;
	double	horhitdistance;
	double	verhitdistance;
	float	xstep;
	float	ystep;
	int		washitvertical;
	int		washithorizantal;
	int		israyfacingup;
	int		israyfacingdown;
	int		israyfacingleft;
	int		israyfacingright;
	char	horizontallhitcontent;
	char	verticalhitcontent;
	char	wallhitcontent;
	float	yintercept;
	float	xintercept;
	t_Point	horizontalhit;
	t_Point	verticalhit;

}	t_ray;

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	my_mlx_get_color(t_img *img, int x, int y);
void			projectionimg(t_data *data, t_ray *ray);
int				render_next_frame(t_data *data);

void			draw_map(t_data *data);
void			draw_line(t_data *data, t_Point a, t_Point b, int color);

void			cast_ray(t_data *data, t_ray *ray);
void			collide(t_data *data, double new_x, double new_y);
void			compdistance(t_ray *ray);
void			castallray(t_data *data);

int				key_handler(int key, t_data *data);

float			normalizeangle(float angle);
double			player_angle(char p);
double			distancebetweenpoints(float x1, float y1, float x2, float y2);
bool			hasWallAt(t_data *data, double x, double y);

void			init_horizantal(t_data *data, t_ray *ray, double rayAngle);
void			init_vertival(t_data *data, t_ray *ray, double rayAngle);
int				find_horizontal_wall_helper(t_data *data, t_ray *ray);
int				find_vertical_wall_helper(t_data *data, t_ray *ray);
void			vertical(t_data *data, t_ray *ray, double rayAngle);
void			horizontal(t_data *data, t_ray *ray, double rayAngle);

void			init_ray(t_ray *ray);
void			init_data(t_data *data);

void			generate3dprojection(t_data *data, t_ray *ray, int i);
void			init_textures(t_data *data);

#endif