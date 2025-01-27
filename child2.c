/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/27 13:22:09 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int pipe_fds[2], t_parsed_data data)
{
	int	fd_out;
	
	dup2(pipe_fds[0], STDIN_FILENO);
	fd_out = open(data.file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1) {
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		display_err("Open failed");
	}
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	exec_cmd2(data);
	display_err("Second command failure");
}
