/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:41:22 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/07 12:22:27 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *cut;
	char *ptr;

	if (!s)
		return (NULL);
	if (!(cut = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = cut;
	while (len--)
		*cut++ = *(s++ + start);
	*cut = '\0';
	return (ptr);
}
