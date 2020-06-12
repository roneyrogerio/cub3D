/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:56:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/12 04:31:41 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isdigit(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_isalpha(int c);
int				ft_toupper(int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *hay, const char *nee, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			*ft_lstnew(void *content);
void			ft_lstadd_front(void **lst, void *new);
int				ft_lstsize(void *lst);
void			*ft_lstlast(void *lst);
void			ft_lstadd_back(void **lst, void *new);
void			ft_lstdelone(void *lst, void (*del)(void*));
void			ft_lstclear(void **lst, void (*del)(void *));
void			ft_lstiter(void *lst, void (*f)(void *));
void			*ft_lstmap(void *lst, void *(*f)(void *),
		void (*del)(void *));

#endif
