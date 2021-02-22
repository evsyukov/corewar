/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:05:45 by nmustach          #+#    #+#             */
/*   Updated: 2019/10/21 17:15:07 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	validate(char **tmp, char **line, int fd)
{
	char	*after;
	size_t	lenbefore;

	lenbefore = 0;
	while (tmp[fd][lenbefore] != '\n' && tmp[fd][lenbefore])
		lenbefore++;
	if (tmp[fd][lenbefore] == '\n')
	{
		MFAIL_GNL((*line = ft_strsub(tmp[fd], 0, lenbefore)));
		MFAIL_GNL((after = ft_strdup(&tmp[fd][lenbefore + 1])));
		ft_strdel(&tmp[fd]);
		tmp[fd] = after;
		if (tmp[fd][0] == '\0')
			ft_strdel(&tmp[fd]);
		return (1);
	}
	MFAIL_GNL((*line = ft_strdup(tmp[fd])));
	ft_strdel(&tmp[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		*new;
	static char	*tmp[255];
	char		buf[BUFF_SIZE_GNL + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE_GNL)) > 0)
	{
		buf[ret] = '\0';
		if (tmp[fd] == NULL)
			MFAIL_GNL((tmp[fd] = ft_strnew(1)));
		MFAIL_GNL((new = ft_strjoin(tmp[fd], buf)));
		ft_strdel(&tmp[fd]);
		tmp[fd] = new;
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && tmp[fd] == NULL)
		return (0);
	return (validate(tmp, line, fd));
}
