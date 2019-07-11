/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:36:25 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 12:58:22 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_base(int type)
{
	int base;

	base = 0;
	if (type == 'x' || type == 'X')
		base = 16;
	else if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'u' || type == 'U')
		base = 10;
	else if (type == 'b')
		base = 2;
	return (base);
}

static int		get_size(unsigned long long nb, int prec, t_flag *all)
{
	int		size;
	int		base;
	int		nb_mem;

	nb_mem = nb;
	base = get_base(all->type);
	size = 0;
	nb == 0 && prec == -1 ? size += 1 : 0;
	(all->type == 'X' || all->type == 'x') && all->hash && nb && !all->zero ?
size += 2 : 0;
	while (nb > 0 || prec > 0)
	{
		size += 1;
		nb /= base;
		prec--;
	}
	(all->type == 'o' || all->type == 'O') && all->hash && ((nb_mem &&
all->precision != 0) || (nb == 0 && all->precision == 0)) ? size += 1 : 0;
	return (size);
}

static void		printer(t_flag *all, unsigned long long nb, int prec)
{
	char	tmp[21];
	int		base;
	int		i;
	int		nb_mem;

	ft_bzero(tmp, 21);
	base = get_base(all->type);
	i = get_size(nb, all->precision, all) - 1;
	nb_mem = nb;
	nb == 0 && (prec == -1 || prec == 0) ? tmp[i--] = '0' : 0;
	while (nb > 0 || prec-- > 0)
	{
		if (nb % base < 10)
			tmp[i--] = nb % base + '0';
		else
			tmp[i--] = nb % base + (all->type == 'X' ? 'A' : 'a') - 10;
		nb /= base;
	}
	(all->type == 'X' || all->type == 'x') && all->hash &&
nb_mem && !all->zero ? tmp[i--] = all->type : 0;
	(all->type == 'X' || all->type == 'x') && all->hash &&
nb_mem && !all->zero ? tmp[i--] = '0' : 0;
	all->type == 'o' && all->hash && ((nb_mem && all->precision != 0) ||
(nb == 0 && all->precision == 0)) ? tmp[i--] = '0' : 0;
	ft_strcat2(tmp, all);
}

void			ft_itoabu(unsigned long long nb, t_flag *all)
{
	int		size;
	int		precision;

	precision = all->precision;
	size = get_size(nb, all->precision, all);
	if ((all->type == 'X' || all->type == 'x') && all->hash && nb && all->zero)
	{
		ft_strcat2(all->type == 'x' ? "0x" : "0X", all);
		all->minsize -= 2;
	}
	while (!all->minus && all->minsize-- > size)
	{
		if (all->zero && (precision != -1 ? (precision++ < size) : 1))
			ft_charcat2('0', all);
		else
			ft_charcat2(' ', all);
	}
	printer(all, nb, all->precision);
	while (all->minus && all->minsize-- > size)
		ft_charcat2(all->zero ? '0' : ' ', all);
}
