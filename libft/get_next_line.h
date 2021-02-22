/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlintill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:48:18 by rlintill          #+#    #+#             */
/*   Updated: 2020/07/18 21:34:27 by rlintill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "sys/stat.h"
# include "unistd.h"
# include "stdlib.h"

# define BUF_SIZE 2048
# define FD_MAX 65535

int get_next_line(const int fd, char **line);

#endif
