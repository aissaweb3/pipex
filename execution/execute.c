/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:40:06 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 10:50:01 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	exec_cmd1(t_parsed_data data)
{
	int 		result;
	char		*args[3];

	args[0] = data.cmd1;
	args[1] = data.file1;
	args[2] = NULL;
    execve(args[0], args, NULL);
}

void	exec_cmd2(t_parsed_data data)
{
	int 		result;
	char		*args[3];

	args[0] = data.cmd2;
	args[1] = "f";
	args[2] = NULL;
    result = execve(args[0], args, NULL);
}
