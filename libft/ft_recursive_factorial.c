/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:47:03 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:21 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 0 && nb <= 12)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
