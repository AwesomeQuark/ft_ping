/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:59:04 by conoel            #+#    #+#             */
/*   Updated: 2019/04/25 16:53:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_H
# define QUIT_H

# include <unistd.h>

void				exit_free(char *msg, int format, ...);
void				exit_(char *msg);
size_t				return_free(char *msg, int format, ...);
size_t				return_(char *msg);

#endif
