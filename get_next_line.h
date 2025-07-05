/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adduarte <adduarte@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-21 14:32:06 by adduarte          #+#    #+#             */
/*   Updated: 2025-06-21 14:32:06 by adduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char 			*get_next_line(int fd);
void			*ft_bzero(void *ptr, size_t num);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strlen(const char *text);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *str);
void			*ft_memcpy(void *dest, const void *str, size_t num);

#endif