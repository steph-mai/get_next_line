/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:28:12 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/02 17:58:14 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	if(!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_is_backslash_n(char *s)
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
static char	ft_extract_line(char *reserve)
{
	int		i;
	size_t	len;
	char	*line;
		
	if (!reserve)
		return (NULL);
	i = ft_is_backslash_n(reserve);
	if (i == -1)
	{
		len = ft_strlen(reserve);
		line = malloc(sizeof(char) * len + 1);
		ft_memcpy(line, reserve, len);
	}		
	else
	{
		len = i;
		line = malloc(sizeof(char) * len + 1);
		ft_memcpy(line, reserve, len);
	}
	line[len] = '\0';
	return (line);
}




















static char *extract_line(char *rest)
{
    int   i;
    char *line;

    if (!rest || rest[0] == '\0')
        return (NULL);
    i = find_newline(rest);
    if (i == -1)
        i = strlen(rest);
    else
        i += 1;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    memcpy(line, rest, i);
    line[i] = '\0';
    return (line);
}

static char *update_rest(char *rest)
{
    int   nl;
    char *new_rest;

    nl = find_newline(rest);
    if (nl == -1)
    {
        free(rest);
        return (NULL);
    }
    new_rest = strdup(rest + nl + 1);
    free(rest);
    return (new_rest);
}