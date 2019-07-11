/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:51:56 by conoel            #+#    #+#             */
/*   Updated: 2019/04/28 16:39:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "garbage.h"

char	*ft_memdup(const char *s, size_t size)
{
	size_t	index;
	char	*end;

	index = 0;
	if (!(end = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	end[size] = '\0';
	while (size-- > 0)
	{
		end[index] = s[index];
		index++;
	}
	return (end);
}
