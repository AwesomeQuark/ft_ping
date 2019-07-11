/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 12:58:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(long long nb, int prec)
{
	int		size;

	size = 0;
	nb == 0 && prec == -1 ? size += 1 : 0;
	if (nb < 0)
	{
		nb /= 10;
		nb = nb * -1;
		if (prec > 0 || prec == -1)
			size++;
		prec--;
	}
	while (nb > 0 || prec > 0)
	{
		size += 1;
		nb /= 10;
		prec--;
	}
	return (size);
}

static void		printer(t_flag *all, long long nb, int prec)
{
	char	tmp[21];
	int		i;
	int		nb_mem;
	int		size;

	size = get_size(nb, all->precision);
	ft_bzero(tmp, 21);
	i = get_size(nb, all->precision) - 1;
	nb_mem = nb;
	nb == 0 && prec == -1 ? tmp[i--] = '0' : 0;
	if (nb < 0)
	{
		if (prec > 0 || prec-- == -1)
			tmp[i--] = (nb % 10) * -1 + '0';
		nb /= 10;
		nb = nb * -1;
	}
	while (nb > 0 || prec-- > 0)
	{
		tmp[i--] = nb % 10 + '0';
		nb /= 10;
	}
	ft_strcat2(tmp, all);
	while (all->minus && all->minsize-- > size)
		ft_charcat2(' ', all);
}

static void		place_sign(int sign_placed, size_t save, long long nb,
t_flag *all)
{
	if (!sign_placed && ((nb >= 0 && all->plus) || nb < 0 ||
(all->space && all->minsize)))
	{
		if (save == all->buffer_index)
		{
			ft_charcat2(all->plus ? '+' : ' ', all);
			all->minsize--;
		}
		all->buffer[all->buffer_index - 1] = all->plus ? '+' : ' ';
		nb < 0 ? all->buffer[all->buffer_index - 1] = '-' : 0;
	}
}

void			ft_itoabs(long long nb, t_flag *all)
{
	int		size;
	int		sign_placed;
	size_t	save;

	save = all->buffer_index;
	size = get_size(nb, all->precision);
	sign_placed = 0;
	while (!all->minus && all->minsize-- > size)
	{
		if (all->zero && all->precision < 0)
			ft_charcat2('0', all);
		else
			ft_charcat2(' ', all);
		if (all->precision < 0 && !sign_placed &&
((nb >= 0 && all->plus) || nb < 0 || all->space) && all->zero)
		{
			sign_placed = 1;
			all->buffer[all->buffer_index - 1] = all->plus ? '+' : ' ';
			nb < 0 ? all->buffer[all->buffer_index - 1] = '-' : 0;
		}
	}
	place_sign(sign_placed, save, nb, all);
	printer(all, nb, all->precision);
}
