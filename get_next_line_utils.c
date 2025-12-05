/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:28:12 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/05 11:08:07 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free_and_null(char *s)
{
	if (s)
		free(s);
	return(NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_join_and_free(char *reserve, char *buffer)
{
	char	*new_str;
	
	if (!reserve)
	{
		reserve = malloc(1);
		if (!reserve)
			return (NULL);
		reserve[0] = '\0';
	}
	if (!buffer)
		return (ft_free_and_null(reserve));
	new_str = malloc(ft_strlen(reserve) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (ft_free_and_null(reserve));
	ft_strcat(new_str, reserve, buffer);	
	free(reserve);
	return (new_str);
}
void	ft_strcat(char *s, char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
	{ 
		s[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		s[i] = src[j];
		i++;
		j++;
	}
	s[i] = '\0';
}