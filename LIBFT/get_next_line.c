/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:16:36 by spariaud          #+#    #+#             */
/*   Updated: 2015/05/03 23:17:36 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void rotate(char *buf, size_t buf_size, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i < buf_size)
	{
		if (i + n < buf_size)
			buf[i] = buf[i + n];
		else
			buf[i] = '\0';
		i++;
	}
}

static int	get_line(char *buf, char **line)
{
	char	c_eol;
	char	*tmp;
	int		end;
	size_t	len_buf;
	size_t	len_count;

	end = ft_memchr(buf, '\n', BUFF_SIZE) ? 1 : 0;
	c_eol = end ? '\n' : '\0';
	len_buf = (char*)ft_memchr(buf, c_eol, BUFF_SIZE + 1) - buf + 1;
	len_count = *line ? ft_strlen(*line) : 0;
	if (!(tmp = ft_strnew(len_count + len_buf)))
		return (-1);
	if (*line)
	{
		ft_strcpy(tmp, *line);
		free(*line);
	}
	ft_memcpy(tmp + len_count, buf, len_buf - 1);
	*line = tmp;
	rotate(buf, BUFF_SIZE, len_buf);
	return (end);
}

int			get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	int				b_read;
	int				ret;
	size_t			count;

	if (BUFF_SIZE < 1 || !line || fd < 0)
		return (-1);
	if (BUFF_SIZE > 0 && line)
	{
		*line = NULL;
		if ((ret = get_line(buf, line)) != 0)
			return (ret);
		count = ft_strlen(buf);
		while ((b_read = read(fd, buf + count, BUFF_SIZE - count)) > 0)
		{
			if ((ret = get_line(buf, line)) != 0)
				return (ret);
		}
		if (!b_read && **line)
			return (1);
		ft_memset(buf, 0, BUFF_SIZE);
		return (0);
	}
	return (-1);
}
