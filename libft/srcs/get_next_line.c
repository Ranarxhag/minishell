/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:29:26 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/23 17:29:27 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(const int fd, char **tab)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	ret = 0;
	while (ft_strchr(tab[fd], '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
		temp = tab[fd];
		if ((tab[fd] = ft_strjoin(temp, buff)) == NULL)
			return (-1);
		ft_strdel(&temp);
	}
	return (1);
}

int		write_line(const int fd, char **tab, char **line)
{
	char *temp;
	char *new_addr;

	if (tab[fd][0] == '\0')
	{
		ft_strdel(&tab[fd]);
		return (0);
	}
	if ((*line = ft_strndup(tab[fd], ft_strclen(tab[fd], '\n'))) == NULL)
	{
		if (tab[fd] != NULL)
			ft_strdel(&tab[fd]);
		return (-1);
	}
	temp = tab[fd];
	if ((new_addr = ft_strchr(temp, '\n')) == NULL)
	{
		if (tab[fd] != NULL)
			ft_strdel(&tab[fd]);
		return (1);
	}
	if ((tab[fd] = ft_strdup(new_addr + 1)) == NULL)
		return (-1);
	ft_strdel(&temp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *tab[OPEN_MAX];
	int			read;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	if (tab[fd] != NULL && ft_strchr(tab[fd], '\n') != NULL)
	{
		write_line(fd, tab, line);
		return (1);
	}
	tab[fd] = ((tab[fd] == NULL) ? ft_strdup("") : tab[fd]);
	if (tab[fd] == NULL)
		return (-1);
	read = read_line(fd, tab);
	if (read == -1)
	{
		if (tab[fd] != NULL)
			ft_strdel(&tab[fd]);
		return (-1);
	}
	return (write_line(fd, tab, line));
}
