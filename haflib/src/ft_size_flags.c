/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:56:53 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 12:57:44 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		char_flags(char ret, t_flag *all)
{
	while (1 < all->minsize && all->minus == 0)
	{
		ft_charcat2(all->zero ? '0' : ' ', all);
		all->minsize--;
	}
	ft_charcat2(ret, all);
	while (1 < all->minsize && all->minus == 1)
	{
		ft_charcat2(' ', all);
		all->minsize--;
	}
}

void		str_flags(char *ret, t_flag *all)
{
	int		i;
	int		size;
	int		prec;

	i = 0;
	prec = all->precision;
	if (ret)
		size = ft_strlen(ret);
	else
		size = 6;
	prec <= -1 ? prec = size : 0;
	while ((all->precision == -1 || all->precision > size ? size :
			all->precision) < all->minsize-- && all->minus == 0)
		ft_charcat2(all->zero == 1 ? '0' : ' ', all);
	if (ret == NULL)
		ft_strlcat2("(null)", all, all->precision);
	while (ret && ret[i] && prec-- > 0)
	{
		ft_charcat2(ret[i++], all);
	}
	while ((all->precision == -1 || all->precision > size ?
size : all->precision) < all->minsize-- + 1 && all->minus == 1)
		ft_charcat2(' ', all);
}
