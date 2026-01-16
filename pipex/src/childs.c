/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:19:21 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/12 16:25:32 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_child1(t_pipex *args)
{
	int		infd;
	char	*path;

	infd = open(args->infile, O_RDONLY);
	if (infd == -1)
	{
		free_commands(args);
		perror("pipex: infile");
		exit(1);
	}
	if (dup2(infd, STDIN_FILENO) == -1 || dup2(args->pipefd[1],
			STDOUT_FILENO) == -1)
	{
		free_commands(args);
		perror("pipex: dup2");
		exit(1);
	}
	close(infd);
	close(args->pipefd[0]);
	close(args->pipefd[1]);
	path = find_cmd_path(args->cmd1_argv[0], args->envp);
	if (!path)
	{
		free_commands(args);
		ft_putendl_fd("pipex: command not found", 2);
		exit(127);
	}
	execve(path, args->cmd1_argv, args->envp);
	perror("pipex: execve");
	exit(1);
}

void	pipex_child2(t_pipex *args)
{
	int		outfd;
	char	*path;

	outfd = open(args->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfd == -1)
	{
		free_commands(args);
		perror("pipex: outfile");
		exit(1);
	}
	if (dup2(args->pipefd[0], STDIN_FILENO) == -1 || dup2(outfd,
			STDOUT_FILENO) == -1)
	{
		free_commands(args);
		perror("pipex: dup2");
		exit(1);
	}
	close(outfd);
	close(args->pipefd[0]);
	close(args->pipefd[1]);
	path = find_cmd_path(args->cmd2_argv[0], args->envp);
	if (!path)
	{
		free_commands(args);
		ft_putendl_fd("pipex: command not found", 2);
		exit(127);
	}
	execve(path, args->cmd2_argv, args->envp);
	free_commands(args);
	free(path);
	perror("pipex: execve");
	exit(0);
}
