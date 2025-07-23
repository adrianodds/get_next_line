/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adduarte <adduarte@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-09 08:47:23 by adduarte          #+#    #+#             */
/*   Updated: 2025-07-09 08:47:23 by adduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *text)
{
	int	count;

	count = 0;
	if (!text)
		return (0);
	while (text[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cp;
	int		l_s1;
	int		i;

	l_s1 = ft_strlen(s1);
	i = -1;
	cp = malloc((l_s1 + ft_strlen(s2) + 1));
	if (!cp)
		return (free(s1), NULL);
	while (s1 && s1[++i])
		cp[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		cp[l_s1 + i] = s2[i];
	cp[l_s1 + i] = '\0';
	free(s1);
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = ft_strlen(s);
	if (!s || start >= len_str)
		return (NULL);
	cp = malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i < len)
		cp[i++] = s[start++];
	cp[i] = '\0';
	return (cp);
}
