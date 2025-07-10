/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adduarte <adduarte@student.42porto.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-21 14:33:14 by adduarte          #+#    #+#             */
/*   Updated: 2025-06-21 14:33:14 by adduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (free(buffer), stash);
}

static char	*extrac_line(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static char	*update_stash(char *stash, char *line)
{
	char	*temp_stash;

	if (!stash)
		return (NULL);
	temp_stash = ft_substr(stash, ft_strlen(line), ft_strlen(stash)
			- ft_strlen(line));
	if (!temp_stash)
	{
		return (free(stash), NULL);
	}
	return (free(stash), temp_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = extrac_line(stash);
	if (!line)
	{
		free(line);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash, line);
	return (line);
}

/* int main(void)
{
	int fd = open("name.txt", O_RDONLY);
	char *line;

	if (fd < 0)
		return (0);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
} */
