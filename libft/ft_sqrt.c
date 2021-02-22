/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:48:07 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int i;
	int c;

	if (nb == 1)
		return (1);
	c = nb / 10;
	i = 0;
	while (nb > 100 && i < c)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	while (nb > 1 && nb <= 100 && i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
