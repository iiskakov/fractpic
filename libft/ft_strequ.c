/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:51:01 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/07 12:20:22 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s2 || !s1)
		return (0);
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	else
		return (1);
}
