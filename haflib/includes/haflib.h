/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haflib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:03:06 by conoel            #+#    #+#             */
/*   Updated: 2019/07/11 05:58:30 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAFLIB_H
# define HAFLIB_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "garbage.h"
# include "ft_printf.h"
# include "quit.h"
# include "ft_is.h"
# include "colors.h"

# define BUFF_SIZE 16
# define ITER_MAX (INT_MAX / BUFF_SIZE)

/*
** PARSING
*/
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char *s, char c);
int					ft_getc(int fd);
char				*get_the_file(int fd);

/*
** DISPLAY
*/
void				print_int_str(int *tabl, size_t len);
void				print_char_str(char c, size_t nb);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** MEMORY ALLOCATION
*/
void				*ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s);
char				*ft_memdup(const char *s, size_t size);
char				*concat(char *s1, char *s2, char *s3);

void				free_tab(char **tabl);
void				ft_memdel(void **ap);

/*
** CONVERSIONS
*/
int					ft_atoi(const char *nptr);
short				ft_atos(char *nb);
char				ft_atoc(char *nb);
long long			ft_strtoll(char *ptr, size_t *index, int base);

/*
** STRING BASICS
*/
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);

/*
** MISC
*/
unsigned int		modulo(int a, int b);
unsigned int		divide(int a, int b);

#endif
