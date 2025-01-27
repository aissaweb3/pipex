/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:29 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/27 21:24:35 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// void	require(void var)
// {

// }

t_parsed_data	parse_data(int ac, char **av, char **env)
{
	t_parsed_data	data;

	if (ac != 5)
		display_err("Bad Usage !!!\n\t./pipex infile cmd1 cmd2 outfile");
	if (env == NULL)
		display_err("ENV not available");
	data.cmd1 = ft_split(av[2], ' ');
	if (data.cmd1 == NULL)
		display_err("Split error");
	data.cmd1[0] = get_path(data.cmd1[0], env);
	data.cmd2 = ft_split(av[3], ' ');
	if (data.cmd2 == NULL)
		display_err("Split error");
	data.cmd2[0] = get_path(data.cmd2[0], env);
	data.infile = av[1];
	data.outfile = av[4];
	data.env = env;
	return (data);
}
