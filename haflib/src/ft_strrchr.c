/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:47:54 by conoel            #+#    #+#             */
/*   Updated: 2018/11/12 16:55:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s);
	while (*s)
		s++;
	while (*s != c && size-- > 0)
		s--;
	return (*s == c ? (char *)s : NULL);
}
