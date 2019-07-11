/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:29:21 by conoel            #+#    #+#             */
/*   Updated: 2019/03/19 16:57:40 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (n--)
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
