/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:15:57 by conoel            #+#    #+#             */
/*   Updated: 2019/04/08 15:19:30 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_malloc
{
	struct s_malloc	*next;
	void			*elem;
}				t_malloc;

void			*malloc_garbage(size_t size);

#endif
