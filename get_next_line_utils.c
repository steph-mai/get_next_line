/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:28:12 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/03 10:06:38 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;

	i = 0;	
	//ajouter securites chaines nulles?
	if (dest == src)
		return (dest);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;		
	}
	return (s2);
}

char *ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;
	
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char *ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	//a proteger plus?
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
