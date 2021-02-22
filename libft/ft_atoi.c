/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:59:07 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_symbols(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' ||
			(str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	unsigned long long	num;
	size_t				i;
	int					minus;

	num = 0;
	minus = 1;
	i = 0;
	i = check_symbols(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num > 9223372036854775807 && minus == 1)
		return (-1);
	if (num > 9223372036854775807 && minus == -1)
		return (0);
	return (num * minus);
}
