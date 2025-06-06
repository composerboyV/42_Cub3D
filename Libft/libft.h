/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:55:27 by sooslee           #+#    #+#             */
/*   Updated: 2025/04/05 14:37:12 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
void	*ft_memset(void *dest, int c, size_t count);
void	*ft_memcpy(void *dest, const void *source, size_t num);
void	*ft_memmove(void *dest, const void *source, size_t num);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
void	*ft_memchr(const void *buf, int c, size_t count);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int C);
int		ft_toupper(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *dest, size_t len);
t_list	*ft_lstnew(void *new_content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
