/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:17:11 by sooslee           #+#    #+#             */
/*   Updated: 2024/04/15 17:31:16 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	where_nextline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char	*reduce_line(char **what_i_read, char **buffer)
{
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (*what_i_read == NULL)
		*what_i_read = ft_strdup("");
	return (NULL);
}

char	*lets_read(char *what_read, int fd, int *newline)
{
	int		how_much_read;
	char	*buffer;

	reduce_line(&what_read, &buffer);
	while (1)
	{
		how_much_read = read(fd, buffer, BUFFER_SIZE);
		if (how_much_read >= 0)
			buffer[how_much_read] = '\0';
		if (how_much_read == -1 || (how_much_read == 0 && what_read[0] == '\0'))
		{
			free(what_read);
			free(buffer);
			return (NULL);
		}
		what_read = ft_strjoin(what_read, buffer);
		*newline = where_nextline(what_read);
		if (*newline != -1 || (how_much_read < BUFFER_SIZE))
		{
			free(buffer);
			return (what_read);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*what_read[1024];
	char		*result;
	char		*temp;
	int			newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	what_read[fd] = lets_read(what_read[fd], fd, &newline);
	if (what_read[fd] == NULL)
	{
		return (NULL);
	}
	if (newline == -1)
	{
		temp = what_read[fd];
		what_read[fd] = NULL;
		free(what_read[fd]);
		return (temp);
	}
	result = ft_substr(what_read[fd], 0, newline + 1);
	temp = ft_substr(what_read[fd], newline + 1, ft_strlen(what_read[fd]));
	free(what_read[fd]);
	what_read[fd] = temp;
	return (result);
}
