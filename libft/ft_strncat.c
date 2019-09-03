/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:45:38 by iiskakov          #+#    #+#             */
/*   Updated: 2019/02/25 20:15:15 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *sc, size_t nb)
{
	int		i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (sc[j] != '\0' && j < nb)
	{
		dest[i] = sc[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
