/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:25:18 by thzeribi          #+#    #+#             */
/*   Updated: 2024/02/23 10:11:03 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <execinfo.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# ifndef END_LINE
#  define END_LINE '\n'
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_check_int_limit(const char *str);
char			*ft_strnew(size_t len);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcpy(char *dest, char *src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
int				ft_putlnbr_base(unsigned long int nb, char *b, int up, int p);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putnbr(int nb);
int				ft_toupper(int c);
char			*ft_strrev(char *str);
int				ft_tolower(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_nbrlen(long int nbr);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_charcat(char *s1, const char s2);
char			*ft_itoa_base(long int num, char *base);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_putnbrmax_fd(long int n, int fd);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
int				init_tab(int *tab, int size);
void			ft_display_file(int fd);
const char		*ft_file_ext(const char *filename, const char ext);
void			ft_memdel(void *ap);
void			ft_stack_trace(char *caller);
int				ft_contain(char *src, char c);
void			ft_swap(int *a, int *b);
char			*get_next_line(int fd);

/*
** -------------------------------------------------------------------
**                             CREDITS
** -------------------------------------------------------------------
**
**              Garbage_Collector based on this project :
**                . https://github.com/rotrojan/libgc .
**              C_Vectors based on this project :
**                . https://github.com/Dirty-No/C_vectors .
**
**              All this project as been rewrite for this Libft
**              The project linked above were just a source
**                            of inspiration.
** -------------------------------------------------------------------
**                       Thanks for them !
** -------------------------------------------------------------------
*/

#endif
