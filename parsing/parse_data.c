/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:29 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 10:58:32 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parsed_data	parse_data(int ac, char **av, char **env)
{
	t_parsed_data	data;

	data.cmd1 = "/bin/cat"; // get_path("ls", env)
	data.cmd2 = "/usr/bin/grep"; // get_path("grep", env)
	data.file1 = "file1.txt";
	data.file2 = "file2.txt";
	return (data);
}
