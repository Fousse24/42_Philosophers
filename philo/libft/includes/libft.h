/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 08:44:19 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/01 19:39:44 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "dlist.h"
# define GNL_BUF_SIZE 40

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Functions */
// Variable types
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isnumber(char *s);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// Number conversions
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned long long int n);
char	*ft_ultoa(unsigned long long int n);
char	*ft_llitoa(long long int n);
char	*ft_nbrtobase(unsigned long nbr, char *base);

// String conversions
int		ft_atoi(const char *nptr);
double	ft_atod(const char *str);

// Numbers and mathematics utilities
int		ft_countdigits(long long int n);
int		ft_countminus(long long int n);
int		ft_power(int n, int ex);

// String utilities
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
int		ft_strpchr(const char *s, int c);

// String manipulations
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strappend(char *dst, const char *src, int len, int f);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2, int f1, int f2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_toupper(int c);
int		ft_tolower(int c);

// Memory management
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_array(void **ptr, void *(f)(void *));
void	*ft_free_split(char **split);
void	*ft_array_clear(void **ptr, void *(f)(void *));

// Printing
void	ft_putchar_fd(unsigned char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Generic list
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// File management
char	*ft_get_next_line(int fd);
/* End functions */

#endif
