/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:31:29 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		leng(long long	int n, int minus)
{
	int numlen;

	numlen = 1;
	while ((n /= 10))
		numlen++;
	return (numlen + minus);
}

char			*ft_itoa(long long int n)
{
	char			*num;
	int				minus;
	long long int	dig;
	int				len;

	dig = 0;
	minus = ((n < 0) ? 1 : 0);
	len = leng(n, minus);
	if ((num = ft_strnew(len)))
	{
		num[len--] = '\0';
		while (len >= minus)
		{
			dig = n % 10;
			if (n < 0)
				num[len--] = (dig * (-1)) + '0';
			else
				num[len--] = dig + '0';
			n /= 10;
		}
		if (minus)
			num[0] = '-';
	}
	return (num);
}
