/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:19:16 by nmustach          #+#    #+#             */
/*   Updated: 2019/10/21 17:44:33 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);
int	validate(char **tmp, char **line, int fd);

# define MFAIL_GNL(x) if (!x) return (-1);
# define BUFF_SIZE_GNL 44

# define BUF_SIZE 2048
# define FD_MAX 65535
#endif
