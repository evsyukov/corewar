/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:48:33 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:21 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcnt(const char *s)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		else if (i == 0)
		{
			i++;
			str++;
		}
		else if (*(str - 1) == ' ' || *(str - 1) == '\n' || *(str - 1) == '\t')
		{
			i++;
			str++;
		}
		else
			str++;
	}
	return (i);
}
