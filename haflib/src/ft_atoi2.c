/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:39 by conoel            #+#    #+#             */
/*   Updated: 2019/03/19 16:58:11 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi2(char *s, t_flag *all)
{
	long long		total;
	int				signe;

	total = 0;
	I = (s[I] == '.') ? I + 1 : I;
	if (s[I] == '*')
	{
		total = va_arg(all->ap, int);
		if (total < 0 && s[I - 1] != '.')
		{
			all->minus = 1;
			total = total * -1;
		}
		return (total);
	}
	signe = (s[I] == '-') ? -1 : 1;
	I = (s[I] == '-' || s[I] == '+') ? I + 1 : I;
	while (s[I] >= '0' && s[I] <= '9')
	{
		total = total * 10 + s[I++] - '0';
	}
	I--;
	return (total * signe);
}
