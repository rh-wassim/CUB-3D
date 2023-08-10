/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:00:55 by wrhilane          #+#    #+#             */
/*   Updated: 2022/02/16 13:11:49 by wrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *str)
{
	char	*buffer;
	int		byte;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (ft_strchr(str, '\n') == 0 && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_one_line(char *str)
{
	int		i;
	char	*al;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		al = malloc(sizeof(char) * (i + 1));
	else
		al = malloc(sizeof(char) * (i + 1));
	if (!al)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		al[i] = str[i];
		i++;
	}
	al[i] = '\0';
	return (al);
}

char	*ft_lines(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[++i])
		new_str[j++] = str[i];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*nl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = ft_get_line(fd, str);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	nl = ft_one_line(str);
	str = ft_lines(str);
	return (nl);
}
