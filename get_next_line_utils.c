/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:28:12 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/04 16:59:36 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	if (!s)
		return (0);
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
	// if (!dest || !src)
	// 	return (NULL);	
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
	
	if (!s)
		return (NULL);	
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new == NULL)
		return (NULL);
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_free_reserve(char *reserve)
{
		free(reserve);
        //reserve = NULL;
        return (NULL);
}