/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 01:09:55 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int pipe_fds[2], t_parsed_data data)
{
	int	fd_in;

	free_split(data.cmd2, 0);
	close(pipe_fds[0]);
	dup2_and_close(data, STDOUT_FILENO, pipe_fds[1]);
	fd_in = open(data.infile, 0);
	if (fd_in == -1)
	{
		free_split(data.cmd1, 0);
		perror(data.infile);
		exit(EXIT_FAILURE);
	}
	dup2_and_close(data, STDIN_FILENO, fd_in);
	execve(data.cmd1[0], data.cmd1, data.env);
	free_split(data.cmd1, 0);
	display_err("First command failure");
}
