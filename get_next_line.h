/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:54:26 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/05 11:06:49 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);

size_t 		ft_strlen(char *s);
char *ft_free_and_null(char *s);
void	ft_strcat(char *s, char *dest, char *src);
//char		*ft_strdup(const char *s);
//void 		*ft_memcpy(void *dest, const void *src, size_t n);
//char 		*ft_strjoin(const char *s1, const char *s2);
//char 		*ft_read_and_handle_reserve(int fd, char *reserve, char *buffer);
//char		*ft_free_reserve(char *reserve);
char	*ft_strchr(char *s, int c);
char	*ft_join_and_free(char *reserve, char *buffer);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#endif