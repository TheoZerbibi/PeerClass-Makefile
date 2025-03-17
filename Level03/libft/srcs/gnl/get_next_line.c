/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:13:42 by thzeribi          #+#    #+#             */
/*   Updated: 2023/02/25 07:02:42 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	*ft_free_str(char *save)
{
	if (save)
		free(save);
	return (NULL);
}

static char
	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	char	*ptr;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	join = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (!join)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	ptr = join;
	if (s1)
	{
		temp = s1;
		while (*s1)
			*join++ = *s1++;
		free(temp);
	}
	if (*s2)
		while (*s2)
			*join++ = *s2++;
	return (*join = '\0', ptr);
}

static void
	ft_reload_buffer(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
	{
		while (str[j++])
			str[i++] = str[j];
		while (str[i])
			str[i++] = '\0';
	}
	else
		while (str[i])
			str[i++] = '\0';
}

static char
	*ft_put_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_str(str));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	ft_free_str(str);
	return (line);
}

char
	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			bytes;
	char		*line;

	bytes = 1;
	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, "", 0) == -1)
		return (ft_free_str(line));
	line = ft_strjoin_gnl(line, buffer[fd]);
	if (!line)
		return (NULL);
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][bytes] = '\0';
		line = ft_strjoin_gnl(line, buffer[fd]);
		if (!line)
			return (ft_free_str(line));
	}
	if (*line)
		line = ft_put_line(line);
	if (bytes < 0 || !line || !*line)
		return (ft_free_str(line));
	ft_reload_buffer(buffer[fd]);
	return (line);
}
