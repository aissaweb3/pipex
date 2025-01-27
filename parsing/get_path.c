/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:30:29 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:18:56 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_split(char **split, int i)
{
	int	j;

	j = i;
	if (split == NULL)
		return ;
	while (split[j])
		free(split[j++]);
	free(split);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	if (env == NULL || cmd == NULL)
		return (NULL);
	path = NULL;
	paths = NULL;
	if (access((const char *)cmd, X_OK) == 0)
		return (cmd);
	if (!ft_strncmp(cmd, "./", 2) || cmd[0] == '/')
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	i = 0;
	if (paths == NULL)
		return (free(cmd), NULL);
	while (paths[i])
	{
		path = ft_strjoin(ft_strjoin(paths[i++], "/"), cmd);
		if (access((const char *)path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	free_split(paths, i);
	free(cmd);
	return (path);
}
