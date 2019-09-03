/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 05:04:51 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/01 05:05:48 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(const char *s, char c)
{
	unsigned int	i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w += 1;
		while (s[i] != c && s[i + 1])
			i += 1;
		i += 1;
	}
	return (w);
}
