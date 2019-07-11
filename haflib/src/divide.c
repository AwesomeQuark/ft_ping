/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 12:22:28 by conoel            #+#    #+#             */
/*   Updated: 2019/05/26 12:25:42 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	divide(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	else
		return (a / b);
}

unsigned int	modulo(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	else
		return (a % b);
}