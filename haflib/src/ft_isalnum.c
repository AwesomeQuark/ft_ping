/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:41:10 by conoel            #+#    #+#             */
/*   Updated: 2019/03/19 16:58:42 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c) ? 1 : 0);
}

int	ft_isalphanum_base(int c, int base, int maj)
{
	char	verif;
	int		iteration;

	verif = 48;
	iteration = 0;
	while (iteration++ <= base)
	{
		if (c == verif)
			return (1);
		verif++;
		if (verif == 59)
			verif = maj ? 'A' : 'a';
	}
	return (0);
}
