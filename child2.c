/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 11:08:26 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int pipe_fds[2], t_parsed_data data)
{
	int	fd_out;
	
	close(pipe_fds[WRITE_IDX]);
	dup2(pipe_fds[READ_IDX], STDIN_FILENO);
	fd_out = open(data.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1) {
		close(pipe_fds[READ_IDX]);
		write(2, "Open failed\n", 12);
		exit(EXIT_FAILURE);
	}
	dup2(fd_out, STDOUT_FILENO);
	exec_cmd2(data);
	close(pipe_fds[READ_IDX]);
	write(2, "Second command failure\n", 23);
	exit(EXIT_FAILURE);
}
