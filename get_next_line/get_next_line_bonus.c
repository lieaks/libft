/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:41:32 by dly               #+#    #+#             */
/*   Updated: 2022/12/07 15:21:11 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *res)
{
	char	*buffer;
	int		readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		res = join_and_free(res, buffer);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*join_and_free(char *res, char *buffer)
{
	char	*join;

	join = ft_strjoin(res, buffer);
	if (res)
		free(res);
	return (join);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_next(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!next)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	next[j] = '\0';
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = save_next(buffer[fd]);
	return (line);
}
/*
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	printf("%d/n", fd);
	if (fd < 0)
		printf("failed\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free(line);
	}
	if (close(fd) < 0)
	{
		printf("close failed\n");
		return (1);
	}
	return (0);
}
*/
