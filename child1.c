/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/27 20:06:15 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int pipe_fds[2], t_parsed_data data)
{
	int	fd_in;

	close(pipe_fds[0]);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	fd_in = open(data.infile, 0);
	if (fd_in == -1)
	{
		perror(data.infile);
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO); // protect
	close(fd_in);
	execve(data.cmd1[0], data.cmd1, data.env);
	display_err("First command failure");
}
