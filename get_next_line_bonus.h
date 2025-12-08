/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:50:56 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/08 10:57:59 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define FD_MAX 1024

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_free_and_null(char *s);
void	ft_strcat(char *s, char *dest, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_join_and_free(char *reserve, char *buffer);

#endif