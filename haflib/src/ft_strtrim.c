/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:52:56 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 14:44:22 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(char const *s)
{
	int		index;
	int		size;

	index = 0;
	size = 0;
	while (s[index] && ft_isspace(s[index]))
		index++;
	while (s[index++])
		size++;
	index -= 2;
	while (s[index] && ft_isspace(s[index]))
	{
		size--;
		index--;
	}
	return (size);
}

char			*ft_strtrim(char const *s)
{
	int		size;
	int		index;
	char	*end;

	if (!s)
		return (NULL);
	size = get_size(s);
	index = 0;
	if (size == 0)
	{
		if (!(end = malloc(sizeof(char *) * size)))
			return (NULL);
	}
	else
	{
		if (!(end = malloc(sizeof(char *) * 1)))
			return (NULL);
	}
	while (*s && ft_isspace(*s))
		s++;
	while (*s && size--)
		end[index++] = *s++;
	end[index] = '\0';
	return (end);
}
