/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:16:42 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/27 20:06:58 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_DATA_H
# define PARSED_DATA_H

typedef struct s_parsed_data
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}				t_parsed_data;

#endif