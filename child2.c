/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 01:10:03 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int pipe_fds[2], t_parsed_data data)
{
	int	fd_out;

	free_split(data.cmd1, 0);
	close(pipe_fds[1]);
	dup2_and_close(data, STDIN_FILENO, pipe_fds[0]);
	fd_out = open(data.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
	{
		free_split(data.cmd2, 0);
		perror(data.outfile);
		exit(EXIT_FAILURE);
	}
	dup2_and_close(data, STDOUT_FILENO, fd_out);
	execve(data.cmd2[0], data.cmd2, data.env);
	free_split(data.cmd2, 0);
	display_err("Second command failure");
}
