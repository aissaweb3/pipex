/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:29 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 17:38:38 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parsed_data	parse_data(int ac, char **av, char **env)
{
	t_parsed_data	data;

	if (ac != 5)
	{
		write(2, "Bad Usage !!!\n", 14);
		write(2, "\t./pipex file1 cmd1 cmd2 file2\n", 31);
		exit(EXIT_FAILURE);
	}
	data.cmd1 = ft_split(av[2], ' ');
	data.cmd1[0] = get_path(ft_strjoin("/", data.cmd1[0]), env);
	data.cmd2 = ft_split(av[3], ' ');
	data.cmd2[0] = get_path(ft_strjoin("/", data.cmd2[0]), env);
	data.file1 = av[1];
	data.file2 = av[4];
	return (data);
}
