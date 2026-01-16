/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:18:35 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/12 15:18:36 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1_str;
	char	*cmd2_str;
	char	**cmd1_argv;
	char	**cmd2_argv;
	char	**envp;
	int		pipefd[2];
}	t_pipex;

void		pipex_run(t_pipex *args);
void		pipex_execute(t_pipex *args);
char		*find_cmd_path(char *cmd, char **envp);
void		pipex_child1(t_pipex *ctx);
void		pipex_child2(t_pipex *ctx);
void		free_commands(t_pipex *args);

#endif
