/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:53:38 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 13:10:05 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "garbage.h"

static int		fill_tab(char *s, char **ret, char c)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (!(ret[j] = malloc(sizeof(char) * (size + 1))))
				return (0);
			ft_bzero(ret[j], size + 1);
			ret[j] = ft_memcpy(ret[j], &(s[i - size]), size);
			j++;
			size = -1;
		}
		size++;
	}
	if (!(ret[j] = malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_bzero(ret[j], size + 1);
	ret[j] = ft_memcpy(ret[j], &(s[i - size]), size);
	return (1);
}

static int		get_nb_word(char *s, char c)
{
	int		nb_word;

	nb_word = 1;
	while (*s)
	{
		if (*s == c)
			nb_word++;
		s++;
	}
	return (nb_word);
}

char			**ft_strsplit(char *s, char c)
{
	char	**ret;
	int		nb_word;

	if (s == NULL)
		return (NULL);
	nb_word = get_nb_word(s, c);
	if (!(ret = malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	ret[nb_word] = NULL;
	if (!(fill_tab(s, ret, c)))
		return (NULL);
	return (ret);
}
