/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:49:38 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_1;
	unsigned char	*temp_2;
	unsigned		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	temp_1 = (unsigned char*)dst;
	temp_2 = (unsigned char*)src;
	while (i < n)
	{
		temp_1[i] = temp_2[i];
		i++;
	}
	return (temp_1);
}
