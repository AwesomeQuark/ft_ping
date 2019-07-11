/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:15:05 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 18:16:09 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init(t_flag *all, int start, int fd)
{
	if (start)
	{
		all->total_size = 0;
		all->buffer_index = 0;
		all->str_index = 0;
		ft_bzero(all->buffer, BUFF + 1);
		all->fd = fd;
	}
	all->intflags = 0;
	all->type = 0;
	all->intflags = 0;
	all->precision = -1;
	all->minsize = 0;
	all->minus = 0;
	all->l = 0;
	all->space = 0;
	all->hash = 0;
	all->plus = 0;
	all->zero = 0;
}

int	if_norme(char s, int type)
{
	if (type == 1)
	{
		if ((s >= '0' && s <= '9') || s == 'd' || s == 'i' || s == 'o'
		|| s == 'u' || s == 'x' || s == 'X' || s == 'c' || s == 's' || s == 'p'
		|| s == 'l' || s == 'h' || s == '%' || s == '.' || s == '-' || s == ' '
		|| s == '+' || s == '#' || s == 'L' || s == '*' || s == 'b' || s == 'O'
		|| s == 'U' || s == 'F' || s == 'm' || s == 'n')
			return (1);
	}
	if (type == 2)
	{
		if (s == 'd' || s == 'i' || s == 'o' || s == 'u' || s == 'x' ||s == 'X'
		|| s == 'c' || s == 's' || s == 'p' || s == '%' || s == 'b' || s == 'O'
		|| s == 'F' || s == 'U' || s == 'm' || s == 'n')
			return (1);
	}
	return (0);
}

void	parse_flags(t_flag *all, char *str)
{
	while (if_norme(str[I], 1) && all->type == 0)
	{
		I++;
		if_norme(str[I], 2) ? all->type = str[I] : 0;
		if (str[I] == 'l')
			all->intflags = all->intflags == 0 ? 1 : 2;
		if (str[I] == 'h')
			all->intflags = all->intflags == 0 ? 3 : 4;
		str[I] == 'L' ? all->l = 1 : 0;
		str[I] == '0' ? all->zero = 1 : 0;
		str[I] == '-' ? all->minus = 1 : 0;
		str[I] == '+' ? all->plus = 1 : 0;
		str[I] == ' ' ? all->space = 1 : 0;
		str[I] == '#' ? all->hash = 1 : 0;
		(str[I] >= '1' && str[I] <= '9') || str[I] == '*' ?
				all->minsize = ft_atoi2(str, all) : 0;
		str[I] == '.' ? all->precision = ft_atoi2(str, all) : 0;
	}
	all->type == 0 ? I-- : 0;
	all->zero == 1 && all->minus == 1 ? all->zero = 0 : 0;
	all->precision < -1 && all->type == 's' ? all->precision *= -1 : 0;
}

int	get_next_arg(t_flag *all, char *str)
{
	init(all, 0, 0);
	parse_flags(all, str);
	all->type == 'd' || all->type == 'i' ? get_int(all) : 0;
	all->type == 'o' || all->type == 'x' || all->type == 'X' ||
	all->type == 'u' || all->type == 'b' || all->type == 'O' ||
	all->type == 'U' ? get_int_base(all) : 0;
	all->type == 'c' || all->type == 'C' ?
	char_flags((char)va_arg(all->ap, int), all) : 0;
	all->type == 'p' ? ft_ptoa(va_arg(all->ap, size_t), all) : 0;
	all->type == 's' ? str_flags(va_arg(all->ap, char *), all) : 0;
	all->type == '%' ? char_flags('%', all) : 0;
	all->type == 'm' ? print_errno(all) : 0;
	all->type == 'n' ? get_charwriten(all) : 0;
	return (0);
}

int			ft_printf(const char *str, ...)
{
	t_flag		all;

	init(&all, 1, 1);
	va_start(all.ap, str);
	while (str[all.str_index])
	{
		if (str[all.str_index] == '%')
			get_next_arg(&all, (char *)str);
		else
			ft_charcat2(str[all.str_index], &all);
		all.str_index++;
	}
	(all.buffer_index != 0) ? write(all.fd, all.buffer, all.buffer_index) : 0;
	va_end(all.ap);
	return (all.total_size + all.buffer_index);
}
