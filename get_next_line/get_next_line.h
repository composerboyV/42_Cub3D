/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:06:44 by sooslee           #+#    #+#             */
/*   Updated: 2025/03/28 21:08:26 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
int		where_next_line(char *what_i_read);
int		find_nextline(char *result);
// size_t	ft_strlen(const char *str);
char	*ft_strjoin2(char const *s1, char const *s2);
// char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
