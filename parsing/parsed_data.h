/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:16:42 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 13:50:43 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_DATA_H
# define PARSED_DATA_H

typedef struct s_parsed_data
{
	char	*file1;
	char	*file2;
	char	**cmd1;
	char	**cmd2;
}				t_parsed_data;

#endif