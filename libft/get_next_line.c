/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: litoulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:35:34 by litoulza          #+#    #+#             */
/*   Updated: 2018/06/27 20:13:05 by litoulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	endline(char *buff)
{
	int		count;

	count = 0;
	while (buff[count] != ENDL && buff[count])
		count++;
	if (buff[count] == ENDL)
	{
		buff[count] = END;
		return (count);
	}
	else
		return (-1);
}

static char	*join(char *buff, char *tab)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	ft_strdel(&buff);
	if (tab)
		ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static int	verif(char **buff, char **tab, char **line)
{
	char	*ptr;
	int		final;

	*buff = join(*buff, *tab);
	final = endline(*buff);
	if (final > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + final + 1);
		ft_strdel(&ptr);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char *buff[BUFF_SIZE + 1];
	char		*tmp;
	int			result;
	int			ret;

	tmp = ft_strnew(BUFF_SIZE + 1);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = verif(&buff[fd], &tmp, line);
		ft_strdel(&tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	ft_strdel(&tmp);
	if ((result = verif(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (result);
}
