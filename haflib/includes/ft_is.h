/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:01:22 by conoel            #+#    #+#             */
/*   Updated: 2019/04/25 16:53:23 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_H
# define FT_IS_H

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalphanum_base(int c, int base, int maj);

#endif
