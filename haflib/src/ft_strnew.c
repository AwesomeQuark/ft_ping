/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:47:16 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 14:44:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*start;
	unsigned long	index;

	index = 0;
	if (!(start = (char *)malloc(size + 1)))
		return (NULL);
	while (index <= size / sizeof(char))
		start[index++] = '\0';
	return (start);
}
