/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:48:33 by iiskakov          #+#    #+#             */
/*   Updated: 2019/04/12 22:58:02 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **l)
{
	static char	*f[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		r;
	ssize_t		i;

	if (fd < 0 || fd > OPEN_MAX || (!f[fd] && !(f[fd] = ft_strnew(1))) || !l)
		return (-1);
	while (!ft_strchr(f[fd], '\n') && (r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = f[fd];
		f[fd] = ft_strjoin(f[fd], buf);
		ft_strdel(&tmp);
	}
	if (r == -1 || !*(tmp = f[fd]))
		return (r == -1 ? -1 : 0);
	if ((i = (ft_strchr(f[fd], '\n') > 0)))
		*l = ft_strsub(f[fd], 0, ft_strchr(f[fd], '\n') - f[fd]);
	else
		*l = ft_strdup(f[fd]);
	f[fd] = ft_strsub(f[fd], (unsigned int)(ft_strlen(*l) + i),
			(size_t)(ft_strlen(f[fd]) - (ft_strlen(*l) + i)));
	ft_strdel(&tmp);
	return (!(!f[fd] && !ft_strlen(*l)));
}
