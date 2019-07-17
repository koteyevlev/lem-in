/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:11:24 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/01 15:37:04 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_delint(int n);
int						ft_digitcount(long long int number);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_islower(int ch);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isupper(int ch);
char					*ft_itoa(int n);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel_content(void *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst,
						const void *src, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memrcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *buf, int ch, size_t count);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int n);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
int						ft_skipspace(const char *s);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *haystack,
const char *needle, size_t len);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_sqrt(int nb);
size_t					ft_w_count(char const *s, char c);
int						ft_cleaner(void **ar1, void ***ar2, void ****ar3);
double					ft_pow(double base, double exp);
long double				ft_powl(long double base, long double exp);
int						ft_atoi_base(const char *str, int base);
int						ft_abs(int nbr);
char					*ft_ltoa(long int n);
char					*ft_lltoa(long long int n);
char					*ft_itoa_base(int val, int base);
char					*ft_lltoa_base(long long int val, int base);
char					*ft_ulltoa_base(unsigned long long int val, int base);
long int				ft_labs(long int n);
char					*ft_utoa(unsigned int n);
char					*ft_ultoa(unsigned long int n);
char					*ft_ulltoa(unsigned long long int n);
unsigned long long int	ft_atollu_base(const char *str, int base);

#endif
