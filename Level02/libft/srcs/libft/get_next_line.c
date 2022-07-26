/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:13:42 by thzeribi          #+#    #+#             */
/*   Updated: 2021/04/28 19:30:40 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_multi_func(const char *str, int argc)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (argc == 0)
	{
		if (!str)
			return (0);
		while (str[i])
			i++;
		return (i);
	}
	else if (argc == 1)
	{
		size = ft_multi_func(str, 0);
		if (str[size] == '\0')
			return (0);
		else if (str[size] == END_LINE)
			return (1);
		return (-1);
	}
	return (0);
}

static char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;
	int	size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_multi_func(s, 0);
	while (i <= size)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

static int	get_line(int fd, char *buffer, char **files)
{
	int		r;
	char	*temp;

	while (ft_strchr_gnl(files[fd], END_LINE) == NULL)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			break ;
		buffer[r] = '\0';
		temp = *files;
		*files = ft_strjoin(temp, buffer);
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)&buffer);
	if (r == -1)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*files[10240];
	char			*buf;
	char			*temp;
	char			*temp2;

	buf = ft_strnew(BUFFER_SIZE);
	if (fd > 10240 || fd < 0 || line == NULL || buf == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!files[fd])
		files[fd] = ft_strnew(1);
	if (!get_line(fd, buf, &files[fd]))
		return (-1);
	temp = ft_strchr_gnl(files[fd], END_LINE);
	if (temp)
	{
		*line = ft_substr(files[fd], 0, temp - files[fd]);
		temp2 = files[fd];
		files[fd] = ft_strdup(temp + 1);
		ft_memdel((void **)&temp2);
		return (1);
	}
	*line = ft_strdup(files[fd]);
	ft_memdel((void **)&files[fd]);
	return (ft_multi_func(*line, 1));
}
