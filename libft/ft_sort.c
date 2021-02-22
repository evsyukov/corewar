/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:47:42 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap_table(int *arr, unsigned int i, unsigned int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static void		bubble_sort(int *arr, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] < arr[j + 1])
				swap_table(arr, j, j + 1);
			j++;
		}
		i++;
	}
}

void			ft_sort(int *arr, unsigned int size)
{
	if (size <= 1)
		return ;
	bubble_sort(arr, size);
}
