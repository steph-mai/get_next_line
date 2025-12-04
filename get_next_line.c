/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:00:37 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/04 17:17:18 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_backslash_n(char *s)
{
	int	i;
	
	if (!s)
		return (-1);
	i = 0;
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

	if (!reserve)
		return (NULL);
	i = ft_is_backslash_n(reserve);
    if (i == -1)
		len = ft_strlen(reserve);
	else
		len = i + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, reserve, len);
    line[len] = '\0';
	return (line);
}

static char *ft_update_reserve(char *reserve)
{
	int		i;
	char	*new_reserve;
	
	if (!reserve)
		return (NULL);
	i = ft_is_backslash_n(reserve);
    if (i == -1)
	{
		free(reserve);
		return (NULL);
	}
	new_reserve = ft_strdup(reserve + i + 1);
	free(reserve);
	return (new_reserve);
}
char	*ft_read_and_handle_reserve(int fd, char *reserve, char *buffer)
{	
	char	*temp;
	int		buf_size = 1;

    while (ft_is_backslash_n(reserve) == -1 && buf_size > 0)
    {
        buf_size = read(fd, buffer, BUFFER_SIZE);
        if (buf_size < 0)
            return (NULL); 
        if (buf_size == 0)
            break;
        buffer[buf_size] = '\0';
        if (!reserve)
            reserve = ft_strdup(buffer);
        else
        {
            temp = ft_strjoin(reserve, buffer);
            if (!temp)
                return (NULL); 
            free(reserve);
            reserve = temp;
        }
    }
    return (reserve);
}

char	*get_next_line(int fd)
{
	static char *reserve = NULL;
	char		*buffer;
    char		*line;
	char		*new_reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	new_reserve = ft_read_and_handle_reserve(fd, reserve, buffer);
	free(buffer);
	if (new_reserve == NULL)  
		reserve = ft_free_reserve(reserve);
	reserve = new_reserve;
	if (!reserve || reserve[0] == '\0')
		reserve = ft_free_reserve(reserve);
	line = ft_extract_line(reserve);
    reserve = ft_update_reserve(reserve);
	return (line);
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
