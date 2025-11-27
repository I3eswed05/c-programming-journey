/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:13:01 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/27 19:42:34 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd)
{
    char	**map = NULL;
    char	*line;
    char	**tmp;
    int		count = 0;

    if (fd < 0)
        return (NULL);
    while ((line = get_next_line(fd)))
    {
        size_t l = ft_strlen(line);
        if (l > 0 && line[l - 1] == '\n')
            line[l - 1] = '\0';
        tmp = malloc(sizeof(char *) * (count + 2));
        if (!tmp)
        {
            free(line);
            while (--count >= 0)
                free(map[count]);
            free(map);
            return (NULL);
        }
        for (int i = 0; i < count; i++)
            tmp[i] = map[i];
        tmp[count] = line;
        tmp[count + 1] = NULL;
        free(map);
        map = tmp;
        count++;
    }
    return (map);
}

int is_ber(char *map)
{
    int i;

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

