/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:01:45 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/12 16:41:22 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_children(int pid2)
{
	int	retstat;
	int	status;
	int	exitstat;

	while (1)
	{
		retstat = waitpid(-1, &status, 0);
		if (retstat == -1)
			break ;
		if (pid2 == retstat)
			exitstat = status;
	}
	if (WIFEXITED(exitstat))
		exit(WEXITSTATUS(exitstat));
	if(WIFSIGNALED(exitstat))
		exit(WTERMSIG(exitstat) + 128);
	// exit(1);
}

void	pipex_execute(t_pipex *args)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("pipex: fork");
		free_commands(args);
		close(args->pipefd[0]);
		close(args->pipefd[1]);
		exit(1);
	}
	if (pid1 == 0)
		pipex_child1(args);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("pipex: fork");
		free_commands(args);
		close(args->pipefd[0]);
		close(args->pipefd[1]);
		exit(1);
	}
	if (pid2 == 0)
		pipex_child2(args);
	close(args->pipefd[0]);
	close(args->pipefd[1]);
	free_commands(args);
	wait_children(pid2);
}
