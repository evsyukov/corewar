/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:25:41 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:21 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	start;
	size_t	finish;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	finish = ft_strlen(s);
	while (s[start] == '\t' || s[start] == ' ' || s[start] == '\n')
		start++;
	while (finish && (s[finish - 1] == '\t' || s[finish - 1] == ' ' ||
		s[finish - 1] == '\n'))
		finish--;
	len = ((finish > start) ? (finish - start) : 0);
	if ((result = ft_strnew(len)))
	{
		while (start < finish)
			result[i++] = s[start++];
		result[i] = '\0';
	}
	return (result);
}
