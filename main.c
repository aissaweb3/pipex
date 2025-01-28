/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:46:19 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:54:59 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_parsed_data	data;
	pid_t			child_process1;
	pid_t			child_process2;
	int				pipe_fds[2];

	data = parse_data(ac, av, env);
	create_pipe(pipe_fds, data);
	create_children(&child_process1, &child_process2, pipe_fds, data);
	if (child_process1 == 0)
		child1(pipe_fds, data);
	if (child_process2 == 0)
		child2(pipe_fds, data);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	wait(NULL);
	wait(NULL);
	free_split(data.cmd1, 0);
	free_split(data.cmd2, 0);
	return (0);
}
