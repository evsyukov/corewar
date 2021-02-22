/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:46:30 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	long long	k;
	int			*i;
	long long	c;

	i = NULL;
	k = max - min;
	if (min >= max)
		return (NULL);
	i = (int*)malloc(k * sizeof(int));
	c = 0;
	while (min < max)
	{
		i[c] = min;
		min++;
		c++;
	}
	return (i);
}
