/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:10:19 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 18:28:40 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_int_base(t_flag *all)
{
	if (all->intflags == 1)
		ft_itoabu(va_arg(all->ap, unsigned long), all);
	else if (all->intflags == 2)
		ft_itoabu(va_arg(all->ap, unsigned long long), all);
	else if (all->intflags == 3)
		ft_itoabu((unsigned short)va_arg(all->ap, unsigned int), all);
	else if (all->intflags == 4)
		ft_itoabu((unsigned char)va_arg(all->ap, unsigned int), all);
	else
		ft_itoabu(va_arg(all->ap, unsigned int), all);
}

void	get_int(t_flag *all)
{
	if (all->intflags == 1)
		ft_itoabs((long)va_arg(all->ap, long long), all);
	else if (all->intflags == 2)
		ft_itoabs((long long)va_arg(all->ap, long long), all);
	else if (all->intflags == 3)
		ft_itoabs((short)va_arg(all->ap, unsigned int), all);
	else if (all->intflags == 4)
		ft_itoabs((char)va_arg(all->ap, unsigned int), all);
	else
		ft_itoabs((int)va_arg(all->ap, unsigned int), all);
}

void	get_pourcent(t_flag *all)
{
	int		size;

	size = 1;
	if (all->minus == 1)
		ft_charcat2('%', all);
	while (all->precision > size)
	{
		size++;
		ft_charcat2('0', all);
	}
	while (all->minsize > size)
	{
		size++;
		ft_charcat2(all->zero ? '0' : ' ', all);
	}
	if (all->minus == 0)
		ft_charcat2('%', all);
}
