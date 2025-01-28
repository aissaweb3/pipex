/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:01:32 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:55:40 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(int fds[2], t_parsed_data data)
{
	if (pipe(fds) == -1)
	{
		free_split(data.cmd1, 0);
		free_split(data.cmd2, 0);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}
