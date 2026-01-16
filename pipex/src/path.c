/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:15:10 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/12 15:17:58 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_three(char *a, char *b, char *c)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(a, b);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, c);
	free(tmp);
	return (res);
}

char	*ft_free_split_ret(char **split, char *ret)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
	}
	return (ret);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*joined;
	int		i;

	if (!cmd || ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_split(get_path_line(envp), ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		joined = ft_strjoin_three(paths[i], "/", cmd);
		if (joined && access(joined, X_OK) == 0)
			return (ft_free_split_ret(paths, joined));
		free(joined);
		i++;
	}
	ft_free_split_ret(paths, NULL);
	return (NULL);
}
