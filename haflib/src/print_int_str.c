/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:10:12 by conoel            #+#    #+#             */
/*   Updated: 2019/03/19 17:00:04 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int_str(int *tab, size_t len)
{
	if (!tab)
		return ;
	while (len--)
	{
		ft_putnbr(*tab);
		ft_putchar('\n');
		tab++;
	}
}
