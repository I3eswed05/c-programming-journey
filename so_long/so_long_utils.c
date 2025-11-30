/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:13:01 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 21:30:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* free a NULL-terminated map */
void	free_map(char **map)
{
    int	i;

    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

/* count lines in a single buffer (used by split_lines) */
static int	count_lines(char *s)
{
    int	i;
    int	lines;

    if (!s || !s[0])
        return (0);
    i = 0;
    lines = 1;
    while (s[i])
    {
        if (s[i] == '\n')
            lines++;
        i++;
    }
    return (lines);
}

/* return 1 if line from get_next_line is empty or only whitespace + newline */
static int	is_empty_line(const char *s)
{
    int i;

    if (!s)
        return (1);
    i = 0;
    /* skip spaces and tabs */
    // while (s[i] && (s[i] == ' ' || s[i] == '\t'))
    //     i++;
    /* if next char is newline or end, it's empty */
    if (s[i] == '\n' || s[i] == '\0')
        return (1);
    return (0);
}

/* split a buffer into heap-allocated lines (no trailing newlines) */
static char	**split_lines(char *s)
{
    char	**map;
    int		lines;
    int		i;
    int		start;
    int		line_idx;

    lines = count_lines(s);
    if (lines <= 0)
        return (NULL);
    map = (char **)malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);
    i = 0;
    line_idx = 0;
    start = 0;
    while (s[i])
    {
        if (s[i] == '\n')
        {
            map[line_idx++] = ft_substr(s, start, i - start);
            start = i + 1;
        }
        i++;
    }
    if (start < i)
        map[line_idx++] = ft_substr(s, start, i - start);
    map[line_idx] = NULL;
    return (map);
}

/* read whole fd into lines using get_next_line (keeps original behavior) */
char	**read_map(int fd)
{
    char	*all;
    char	*line;
    char	*tmp;
    char	**map;

    all = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        /* ignore trailing empty lines after first empty */
        if (is_empty_line(line))
        {
            free(line);
            continue ;
        }
        tmp = all;
        if (!all)
            all = ft_strdup(line);
        else
            all = ft_strjoin(all, line);
        free(line);
        if (tmp)
            free(tmp);
    }
    if (!all)
        return (NULL);
    map = split_lines(all);
    free(all);
    return (map);
}

int	is_ber(char *map)
{
    int	i;

    if (!map)
        return (0);
    i = ft_strlen(map);
    if (i <= 4)
        return (0);
    if (map[i - 4] != '.' || map[i - 3] != 'b'
        || map[i - 2] != 'e' || map[i - 1] != 'r')
        return (0);
    return (1);
}
