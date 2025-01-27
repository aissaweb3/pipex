/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/27 20:06:34 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int pipe_fds[2], t_parsed_data data)
{
	int	fd_out;

	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[0]);
	fd_out = open(data.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
	{
		perror(data.outfile);
		exit(EXIT_FAILURE);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(data.cmd2[0], data.cmd2, data.env);
	display_err("Second command failure");
}
