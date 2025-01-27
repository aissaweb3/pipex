/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:16:42 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:37:16 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "parsed_data.h"
# include "../pipex.h"

t_parsed_data	parse_data(int ac, char **av, char **env);
char			*get_path(char *cmd, char **env);
void			display_err(char *str);
void			free_split(char **split, int i);

#endif