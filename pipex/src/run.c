/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:48:50 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/12 16:27:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_commands(t_pipex *args)
{
	int	i;

	i = 0;
	if (args->cmd1_argv)
	{
		while (args->cmd1_argv[i])
		{
			free(args->cmd1_argv[i]);
			i++;
		}
		free(args->cmd1_argv);
	}
	i = 0;
	if (args->cmd2_argv)
	{
		while (args->cmd2_argv[i])
		{
			free(args->cmd2_argv[i]);
			i++;
		}
		free(args->cmd2_argv);
	}
}

static int	parse_commands(t_pipex *args)
{
	args->cmd1_argv = ft_split(args->cmd1_str, ' ');
	if (!args->cmd1_argv)
	{
		free_commands(args);
		return (1);
	}
	args->cmd2_argv = ft_split(args->cmd2_str, ' ');
	if (!args->cmd2_argv)
	{
		free_commands(args);
		return (1);
	}
	return (0);
}

void	pipex_run(t_pipex *args)
{
	if (parse_commands(args))
		exit(1);
	if (pipe(args->pipefd) == -1)
	{
		perror("pipex: pipe");
		free_commands(args);
		exit(1);
	}
	pipex_execute(args);
	free_commands(args);
	exit(0);
}
