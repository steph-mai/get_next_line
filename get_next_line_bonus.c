/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:48:49 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/08 10:51:52 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(int fd, char *reserve)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_and_null(reserve));
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(reserve, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free (buffer);
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

static char	*ft_update_reserve(char *reserve)
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
	static char	*reserve[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	reserve[fd] = ft_read_file(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	line = ft_get_line(reserve[fd]);
	if (!line)
	{
		free(reserve[fd]);
		reserve[fd] = NULL;
		return (NULL);
	}
	reserve[fd] = ft_update_reserve(reserve[fd]);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	char	*line;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if(fd1 == -1 || fd2 == -1)
// 	{
// 		printf("erreur lors de l'ouverture du fichier\n");
// 		return(-1);
// 	}
// 	line = get_next_line(fd1);
// 	printf ("fd1[0] = %s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf ("fd2[0] = %s\n", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf ("fd1[1] = %s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf ("fd2[1] = %s\n", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf ("fd1[2] = %s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf ("fd2[2] = %s\n", line);
// 	free(line);

// 	close(fd1);
// 	close(fd2);
// }
