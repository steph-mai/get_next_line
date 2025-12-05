/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:00:37 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/05 13:41:53 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(int fd, char *reserve)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_and_null(reserve));
	read_bytes = 1;
	while (!ft_strchr(reserve, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (ft_free_and_null(reserve));
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		reserve = ft_join_and_free(reserve, buffer);
		if (!reserve)
			return (ft_free_and_null(buffer));
	}
	free(buffer);
	return (reserve);
}

static char	*ft_get_line(char *reserve)
{
	int		i;
	char	*line;

	i = 0;
	if (!reserve || !reserve[0])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (reserve[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_clean_reserve(char *reserve)
{
	int		i;
	int		j;
	char	*new_reserve;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	new_reserve = malloc(ft_strlen(reserve) - i + 1);
	if (!new_reserve)
	{
		free(reserve);
		return (NULL);
	}
	i++;
	j = 0;
	while (reserve[i])
		new_reserve[j++] = reserve[i++];
	new_reserve[j] = '\0';
	free(reserve);
	return (new_reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = ft_read_file(fd, reserve);
	if (!reserve)
		return (NULL);
	line = ft_get_line(reserve);
	if (!line)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	reserve = ft_clean_reserve(reserve);
	return (line);
}
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if(argc != 2)
// 		return(-1);
// 	fd = open(argv[1], O_RDONLY);
// 	while((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }
