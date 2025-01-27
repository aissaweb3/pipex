/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:20:19 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:28:55 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	dup2_and_close(t_parsed_data data, int from, int to)
{
	int	res;

	res = dup2(to, from);
	close(to);
	if (res == -1)
	{
		free_split(data.cmd1, 0);
		free_split(data.cmd2, 0);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}
