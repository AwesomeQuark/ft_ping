/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:25:56 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 16:03:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0 || !s1 || !s2)
		return (-1);
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && i < n - 1)
	{
		i++;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
