/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:16:57 by conoel            #+#    #+#             */
/*   Updated: 2019/05/17 16:37:25 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

static t_malloc		*get_top(t_malloc *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

static void			free_everything(t_malloc *head)
{
	t_malloc	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		if (head->elem != NULL)
			free(head->elem);
		free(head);
		head = tmp;
	}
}

static t_malloc		*init_garbage(int size)
{
	t_malloc	*head;

	if (!(head = malloc(sizeof(t_malloc))))
		return (NULL);
	head->next = NULL;
	if (!(head->elem = malloc(size)))
		return (NULL);
	return (head);
}

static int			add_mem(t_malloc *head, int size)
{
	t_malloc	*new;

	if (!(new = malloc(sizeof(t_malloc))))
		return (0);
	new->next = NULL;
	if (!(new->elem = malloc(size)))
		return (0);
	get_top(head)->next = new;
	return (1);
}

void				*malloc_garbage(size_t size)
{
	static t_malloc	*head = NULL;

	if (head == NULL && size > 0)
	{
		if (!(head = init_garbage(size)))
			return (NULL);
	}
	else if (size > 0)
	{
		if (!(add_mem(head, size)))
			return (NULL);
	}
	else if (size == 0 && head != NULL)
	{
		free_everything(head);
		head = NULL;
		return (NULL);
	}
	return (get_top(head)->elem);
}
