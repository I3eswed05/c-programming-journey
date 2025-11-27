/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:08:03 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/27 19:57:01 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);

/* get_next_line and helpers */
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* project functions */
int		is_ber(char *map);
char	**read_map(int fd);
int		is_rectangle(char **map);
int		validation(char **map);
int		count_components(char **map);
void 	free_map(char **map);
char	**copy_map(char **map);
int     count_help(char ch, int *c, int *e, int *p);
int     check_paths(char **map);


#endif