/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 18:15:04 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcat2(char *arg, t_flag *all)
{
	if (arg == NULL)
		return ;
	while (*arg)
	{
		all->buffer[all->buffer_index++] = *arg++;
		if (all->buffer_index >= BUFF)
		{
			write(all->fd, all->buffer, BUFF);
			ft_bzero(all->buffer, BUFF + 1);
			all->total_size += BUFF;
			all->buffer_index = 0;
		}
	}
}

void	ft_charcat2(char arg, t_flag *all)
{
	all->buffer[all->buffer_index++] = arg;
	if (all->buffer_index >= BUFF)
	{
		write(all->fd, all->buffer, BUFF);
		ft_bzero(all->buffer, BUFF + 1);
		all->total_size += BUFF;
		all->buffer_index = 0;
	}
}

void	ft_strlcat2(char *arg, t_flag *all, size_t size)
{
	if (arg == NULL)
		return ;
	while (*arg && size--)
	{
		all->buffer[all->buffer_index++] = *arg++;
		if (all->buffer_index >= BUFF)
		{
			write(all->fd, all->buffer, BUFF);
			ft_bzero(all->buffer, BUFF + 1);
			all->total_size += BUFF;
			all->buffer_index = 0;
		}
	}
}
