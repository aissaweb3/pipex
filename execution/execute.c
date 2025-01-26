/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:40:06 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 14:33:09 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	exec_cmd1(t_parsed_data data)
{
	execve(data.cmd1[0], data.cmd1, NULL);
}

void	exec_cmd2(t_parsed_data data)
{
	execve(data.cmd2[0], data.cmd2, NULL);
}
