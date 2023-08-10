/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrikel <ofrikel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:12:58 by wrhilane          #+#    #+#             */
/*   Updated: 2023/07/27 23:16:02 by ofrikel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	colors_check(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			ft_error("To much commas");
		else if (line[i] == ',')
			c++;
		i++;
	}
	if (c != 2 || line[i - 1] == ',')
		ft_error("Color");
}

void	free_double(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int set_colors(char *line)
{
    char    **rgb;
    char    **color;
    int     r;
    int     g;
    int     b;

    colors_check(line);
    color = ft_split(line, ' ');
    if (color[2] || !color[1])
        ft_error("Color elements not set very well");
    rgb = ft_split(color[1], ',');
    
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
        ft_error("Color does not set correctly!");

    if (!is_integer(rgb[0]) || !is_integer(rgb[1]) || !is_integer(rgb[2]))
        ft_error("Color values must be integers!");

    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);

    free_double(rgb);
    free_double(color);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        ft_error("Color values are out of range!");

    return (r << 16 | g << 8 | b);
}

void	set_pars_helper(int fd, t_pars *map, char *line)
{
	if (!line)
		ft_error("Empty file!");
	while (line)
	{
		if (check_wall(line) || line[0] == '1')
		{
			if (map->flag == -1)
				map->flag = 0;
			map->nb_line++;
		}
		else if (!map->flag)
			map->flag = 1;
		if ((check_wall(line) || line[0] == '1') && map->flag)
			ft_error("map error");
		free(line);
		line = get_next_line(fd);
	}
}

void	set_pars(char *file, t_pars *map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!");
	line = get_next_line(fd);
	set_pars_helper(fd, map, line);
	close(fd);
	map->l_map = malloc(sizeof(char *) * (map->nb_line + 1));
	map->l_map[0] = NULL;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	check_textures(map, line, fd);
	if (map->nb_line == 0)
		ft_error("map not set yet!");
}
