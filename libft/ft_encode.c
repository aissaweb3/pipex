/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:48:35 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/26 16:48:49 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_encode(char *s)
{
	char	open_quote;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	open_quote = -1;
	while (s[i])
	{
		if (s[i] == ' ' && open_quote == 1)
			s[i] = 3;
		if (s[i] == '\'')
		{
			open_quote *= -1;
			s[i] = ' ';
		}
		i++;
	}
	return (s);
}
