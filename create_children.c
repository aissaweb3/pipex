/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:05:08 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:59:27 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_children(int *cp1, int *cp2, int pipe_fds[2], t_parsed_data data)
{
	*cp1 = fork();
	*cp2 = -314;
	if (*cp1 > 0)
		*cp2 = fork();
	if (*cp1 == -1 || *cp2 == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		free_split(data.cmd1, 0);
		free_split(data.cmd2, 0);
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
