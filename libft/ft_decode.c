/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:37:56 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/01/28 00:37:58 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_decode(char *s)
{
	char	open_quote;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	open_quote = -1;
	while (s[i])
	{
		if (s[i] == 3 && open_quote == 1)
			s[i] = ' ';
		if (s[i] == '\'')
			open_quote *= -1;
		i++;
	}
	return (s);
}
