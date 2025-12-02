/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:11:06 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/02 17:43:11 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char *ft_get_next_line(int fd)
{
    static char *reserve;
    char        *buffer;
    size_t     	buf_size;
    char        *temp;
    char        *line;
	
	reserve = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <=0 || buffer == -1)
		return (NULL);
	while (ft_is_backslash_n == -1)
	{
		buf_size = read(fd, buffer, BUFFER_SIZE);
		if (buf_size <= 0)
			break;
		buffer[buf_size] = '\0';
		if (!reserve)
			reserve = ft_strdup(buffer);
		else
		{
			temp = malloc(sizeof(char) * ft_strlen(reserve) + buf_size + 1);
			ft_strcpy(temp, reserve);
			ft_strcat(temp, buffer);
			free(reserve);
			reserve = temp;
		}
	}
	line = ft_extract_line(reserve);
	reserve = ft_update_reserve(reserve);
	return(line);
}
