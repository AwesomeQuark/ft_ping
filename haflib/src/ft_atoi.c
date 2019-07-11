/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:39 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 13:02:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int total;
	int signe;

	total = 0;
	while (ft_isspace(*nptr))
		nptr++;
	signe = (*nptr == '-') ? -1 : 1;
	nptr = (*nptr == '-' || *nptr == '+') ? nptr + 1 : nptr;
	while (ft_isdigit(*nptr))
		total = total * 10 + *nptr++ - 48;
	return (total * signe);
}
