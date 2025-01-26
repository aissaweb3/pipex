/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:13:31 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 17:29:56 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int pipe_fds[2], t_parsed_data data)
{
	dup2(pipe_fds[WRITE_IDX], STDOUT_FILENO);
	dup2(open(data.file1, 0), STDIN_FILENO); // protect
	exec_cmd1(data);
	close(pipe_fds[READ_IDX]);
	close(pipe_fds[WRITE_IDX]);
	write(2, "First command failure\n", 22);
	exit(EXIT_FAILURE);
}
