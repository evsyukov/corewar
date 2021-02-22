/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:38:04 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*temp;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	temp = (char *)haystack;
	if (!(needle_len = ft_strlen(needle)))
		return (temp);
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (needle[j] && needle[j] == temp[i + j])
			j++;
		if (j == needle_len)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
