/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:03 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:57:16 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "parsing/parsing.h"
# include "libft/libft.h"

// main function
void	create_pipe(int fds[2], t_parsed_data data);
void	create_children(int *cp1, int *cp2, int pipe_fds[2],
			t_parsed_data data);
void	child1(int pipe_fds[2], t_parsed_data data);
void	child2(int pipe_fds[2], t_parsed_data data);

// utils
void	dup2_and_close(t_parsed_data data, int from, int to);

#endif