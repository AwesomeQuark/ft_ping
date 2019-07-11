/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:02:21 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 13:02:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_atoc(char *nb)
{
	char	ret;
	int		sign;

	ret = 0;
	if (!nb || *nb == '\0')
		return (0);
	if (*nb == '-')
	{
		sign = -1;
		nb++;
	}
	else
		sign = 0;
	while (*nb && ft_isdigit(*nb))
	{
		ret = ret * 10;
		ret += *nb + '0';
		nb++;
	}
	return (ret);
}
