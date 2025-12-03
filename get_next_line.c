/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:11:06 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/03 17:42:32 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static int  prev_fd = -1;

static int	ft_is_backslash_n(char *s)
{
	int	i;
	
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_extract_line(char *reserve)
{
	int		i;
	size_t	len;
	char	*line;
		
	i = ft_is_backslash_n(reserve);
	if (i == -1)
		len = ft_strlen(reserve);
	else
		len = i + 1;	
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, reserve, len);
	line[len] = '\0';
	return (line);
}
static char *ft_update_reserve(char *reserve)
{
	int	i;
	char *new_reserve;
	
	i = ft_is_backslash_n(reserve);
	if (i == -1)
	{
		free(reserve);
		return (NULL);
	}
	else
	{
		new_reserve = ft_strdup(reserve + i + 1);
		free(reserve);
		if (new_reserve[0] == '\0')
		{
			free(new_reserve);
			return(NULL);	
		}
		return (new_reserve);
	}
}
char *get_next_line(int fd)
{
    static char *reserve;
    char        *buffer;
    size_t     	buf_size;
    char        *temp;
    char        *line;
	

	buf_size = 1;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		reserve = NULL;
    	return (NULL);
	}
	if (fd != prev_fd)
	{
    	reserve = NULL;
    	prev_fd = fd;
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
    	return (NULL);
	while (ft_is_backslash_n(reserve) == -1 && buf_size > 0)
	{
		buf_size = read(fd, buffer, BUFFER_SIZE);
		if (buf_size <= 0)
			break;
		buffer[buf_size] = '\0';
		if (!reserve)
			reserve = ft_strdup(buffer);
		else
		{
			temp = malloc(ft_strlen(reserve) + ft_strlen(buffer) + 1);
			//premiere version = (ft_strlen(reserve) + buf_size + 1));
			//2eme 
			//temp = malloc(sizeof(char) * ft_strlen(reserve) + ft_strlen(buffer) + 1);
			if (!temp)
			{
				free(buffer);
				return (NULL);
			}
			ft_strcpy(temp, reserve);
			ft_strcat(temp, buffer);
			free(reserve);
			reserve = temp;
		}
	}
	if (!reserve)
	{
    	free(buffer);
    	return (NULL);
	}
	line = ft_extract_line(reserve);
	reserve = ft_update_reserve(reserve);
	free(buffer);
	return(line);
}
// #include <stdio.h>

// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
// }

