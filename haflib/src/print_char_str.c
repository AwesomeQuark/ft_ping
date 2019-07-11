/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 01:03:37 by conoel            #+#    #+#             */
/*   Updated: 2019/04/19 14:44:22 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_str(char c, size_t nb)
{
	char	*buff;
	int		i;

	i = nb;
	if (!(buff = malloc(sizeof(char) * nb + 1)))
		exit_(NULL);
	while (i--)
		buff[i] = c;
	write(1, buff, nb);
	free(buff);
}
