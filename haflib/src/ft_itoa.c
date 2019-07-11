/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:05:18 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 14:44:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char	*end;
	int		size;

	size = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(end = (char *)malloc(sizeof(char) * size--)))
		return (0);
	end[size--] = '\0';
	if (n < 0)
	{
		end[0] = '-';
		n *= -1;
	}
	if (n == 0)
		end[0] = 48;
	while (n)
	{
		end[size--] = n % 10 + 48;
		n = n / 10;
	}
	return (end);
}
