/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:14:01 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/27 23:19:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangle(char **map)
{
    size_t len;
    int i;

    if (!map || !map[0])
        return (0);
    len = ft_strlen(map[0]);
    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

int validation(char **map)
{
    if (!is_rectangle(map) || !count_components(map))
        return(0);
    if (!check_paths(map))
    {
        write (1, "Error\ninvalid paths", 14);
        return (0);
    }
    return (1);
    
}
int count_help(char map, int *c, int*e, int *p)
{
    if (map == 'P')
    {
        (*p)++;
        return (1);
    }
    else if (map == 'C')
    {
        (*c)++;
        return (1);
    }
    if (map == 'E')
    {
        (*e)++;
        return (1);
    }
    if (map == '1' || map == '0')
        return (1);
    return (0);
}

int	valid_borders(char **map)
{
	int	lines;
	int	i;
	int	j;


	lines = 0;
	while (map[lines])
		lines++;
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < ft_strlen(map[0]))
		{
			if ((i == 0 || i == lines - 1) && map[i][j] != '1')
					return (0);
			else if ((j == 0 || j == ft_strlen(map[0]) - 1) && map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int count_components(char **map)
{
    int c;
    int e;
    int p;
    int i;
    int j;

    c = 0;
    e = 0;
    p = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!count_help(map[i][j], &c, &e, &p))
                return (0);
            j++;
        }
        i++;
    }
    if (!valid_borders(map))
        return (0);
    if (p != 1 || e != 1 || c < 1)
        return (0);
    return (1);
}
char    **copy_map(char **map)
{
    int     count;
    char    **new_map;
    int     i;

    if (!map)
        return (NULL);
    count = 0;
    while (map[count])
        count++;
    new_map = malloc(sizeof(char *) * (count + 1));
    if (!new_map)
        return (NULL);
    i = 0;
    while (i < count)
    {
        new_map[i] = ft_strdup(map[i]);
        if (!new_map[i])
        {
            free_map(new_map);
            return (NULL);
        }
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}
