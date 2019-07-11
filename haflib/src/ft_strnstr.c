/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:47:29 by conoel            #+#    #+#             */
/*   Updated: 2018/11/12 17:08:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	size;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	while (*haystack && n-- >= size)
	{
		if (ft_strncmp(haystack, needle, size) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ((char *)NULL);
}
