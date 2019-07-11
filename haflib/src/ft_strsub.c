/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:31:25 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 14:44:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*end;

	if (!s)
		return (0);
	if (!(end = (char *)malloc(len + 1)))
		return (NULL);
	end = ft_strncpy(end, (s + start), len);
	end[len] = '\0';
	return (end);
}
