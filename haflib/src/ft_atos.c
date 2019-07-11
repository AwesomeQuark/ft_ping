/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:43:32 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 13:02:33 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_atos(char *nb)
{
	short	ret;
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
