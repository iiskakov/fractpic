/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:09:47 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/28 15:13:13 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <unistd.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **lines);

#endif
