/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:22:48 by conoel            #+#    #+#             */
/*   Updated: 2019/05/26 12:26:02 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 256
# define ITER_MAX (INT_MAX / BUFF_SIZE)
# define BUFF 2048
# define I all->str_index

int					ft_atoi(const char *nptr);
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
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*concat(char *s1, char *s2, char *s3);
unsigned int		modulo(int a, int b);
unsigned int		divide(int a, int b);
char				*ft_strjoin(char const *s1, char const *s2);
void				exit_free(char *msg, int format, ...);
void				exit_(char *msg);
char				**ft_strsplit(char *s, char c);
void				print_char_str(char c, size_t nb);
long long			ft_strtoll(char *ptr, size_t *index, int base);
int					ft_getc(int fd);
char				*get_the_file(int fd);
void				free_tab(char **tab);
int					ft_isalphanum_base(int c, int base, int maj);
void				*ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s);
char				*ft_memdup(const char *s, size_t size);
void				print_int_str(int *tab, size_t len);
char				ft_atoc(char *nb);
short				ft_atos(char *nb);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
/*
**############### PRINTF ################
*/
typedef struct		s_flag
{
	char	buffer[BUFF + 1];
	va_list	ap;
	size_t	buffer_index;
	size_t	str_index;
	int		fd;
	int		total_size;
	char	type;
	char	intflags;
	int		precision;
	int		minsize;
	char	minus;
	char	plus;
	char	l;
	char	space;
	char	hash;
	char	zero;
}					t_flag;

int					ft_atoi2(char *s, t_flag *all);
void				ft_strrev(char *str);

/*
**itoabu stands for : integer to array base unsigned
**itoabs stands for : integer to array base signed
*/
void				ft_ftoa(long double num, t_flag *all);
void				ft_itoabu(unsigned long long nb, t_flag *all);
void				ft_itoabs(long long nb, t_flag *all);
void				ft_ptoa(size_t nb, t_flag *flags);
void				char_flags(char ret, t_flag *all);
void				str_flags(char *ret, t_flag *all);
void				print(char *ret, t_flag *all);
void				ft_strcat2(char *arg, t_flag *all);
void				ft_charcat2(char arg, t_flag *all);
void				ft_strlcat2(char *arg, t_flag *all, size_t size);

void				get_int(t_flag *flags);
void				get_int_base(t_flag *flags);
void				get_pourcent(t_flag *flags);
void				get_float(t_flag *all);
void				get_nothing(t_flag *all);
void				print_errno(t_flag *all);
void				get_charwriten(t_flag *all);
void				init(t_flag *all, int start, int fd);
int					if_norme(char s, int type);
void				parse_flags(t_flag *all, char *str);
int					get_next_arg(t_flag *all, char *str);

int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);

#endif
