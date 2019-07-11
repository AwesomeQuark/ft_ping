/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:42:58 by conoel            #+#    #+#             */
/*   Updated: 2018/11/11 15:33:40 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	st;

	dst1 = (char *)dst;
	src1 = (char *)src;
	st = -1;
	if (dst1 > src1)
		while ((int)--len >= 0)
			*(dst1 + len) = *(src1 + len);
	else
		while (++st < len)
			*(dst1 + st) = *(src1 + st);
	return (dst);
}
