/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:11:57 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 18:17:51 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dprintf(int fd, const char *str, ...)
{
	t_flag		all;

	init(&all, 1, fd);
	va_start(all.ap, str);
	while (str[all.str_index])
	{
		if (str[all.str_index] == '%')
			get_next_arg(&all, (char *)str);
		else
			ft_charcat2(str[all.str_index], &all);
		all.str_index++;
	}
	(all.buffer_index != 0) ? write(fd, all.buffer, all.buffer_index) : 0;
	va_end(all.ap);
	return (all.total_size + all.buffer_index);
}