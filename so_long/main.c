/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:07:12 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/27 23:13:02 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
    char	**map;
    int		fd;

    if (ac != 2)
        return (1);
    if (!is_ber(av[1]))
    {
        write(2, "Error\nInvalid map extension\n", 28);
        return (1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\ncould not open map\n", 25);
        return (1);
    }
    map = read_map(fd);
    close(fd);
    if (!map)
    {
        write(2, "Error\nmap is empty\n", 19);
        return (1);
    }
    if (!validation(map))
    {
        write(2, "Error\ninvalid elements In Map\n", 30);
        free_map(map);
        return (1);
    }
    free_map(map);
    return (0);
}
