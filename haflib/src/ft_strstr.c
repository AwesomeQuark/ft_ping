/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:48:03 by conoel            #+#    #+#             */
/*   Updated: 2018/11/12 16:58:19 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, size) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
