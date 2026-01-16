/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:33:55 by ialausud          #+#    #+#             */
/*   Updated: 2026/01/14 15:47:10 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipx file1 cmd1 cmd2 file2

#include "pipex.h"

static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	args;

	if (argc != 5)
	{
		print_usage();
		return (1);
	}
	args.infile = argv[1];
	args.cmd1_str = argv[2];
	args.cmd2_str = argv[3];
	args.outfile = argv[4];
	args.envp = envp;
	pipex_run(&args);
}
