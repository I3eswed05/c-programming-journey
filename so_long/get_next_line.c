/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:30:03 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/27 19:39:10 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*new_stash(char *stash);
static char	*join_stash(char *stash, char *buffer);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = new_stash(stash);
	return (line);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes = 0;
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		stash = join_stash(stash, buffer);
		if (!stash)
			break ;
	}
	free(buffer);
	if (bytes == -1)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_strdup(stash);
	return (line);
}

static char	*new_stash(char *stash)
{
	size_t	i;
	char	*new;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (new);
}

static char	*join_stash(char *stash, char *buffer)
{
	char	*joined;

	if (!stash)
		return (ft_strdup(buffer));
	joined = ft_strjoin(stash, buffer);
	if (!joined)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (joined);
}
