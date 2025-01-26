/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:03 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 17:59:01 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#         include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include "parsing/parsing.h"
#include "libft/libft.h"
#include "execution/execution.h"

#define READ_IDX 0
#define WRITE_IDX 1

void	create_pipe(int fds[2]);
void	create_children(int *cp1, int *cp2, int pipe_fds[2]);
void	child1(int pipe_fds[2], t_parsed_data data);
void	child2(int pipe_fds[2], t_parsed_data data);
