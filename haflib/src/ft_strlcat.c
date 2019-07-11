/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:45:53 by conoel            #+#    #+#             */
/*   Updated: 2018/11/12 16:42:53 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dsts;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dsts = i;
	while (src[i - dsts] && i < size - 1 && size != 0)
	{
		dst[i] = src[i - dsts];
		i++;
	}
	if (dsts < size)
		dst[i] = '\0';
	return (dsts + ft_strlen(src));
}
