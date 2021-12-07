/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:57 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/24 16:22:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	ft_init_buf(char **buf)
{
	if (buf && *buf == NULL)
		*buf = ft_calloc(GNL_BUF_SIZE + 1, sizeof(char));
}

static int	ft_read_nl(char **buf, int fd)
{
	int	b_read;

	b_read = 0;
	if (**buf == '\0')
	{
		b_read = read(fd, *buf, GNL_BUF_SIZE);
		if (b_read >= 0)
			(*buf)[b_read] = '\0';
	}
	else
		return (ft_strlen(*buf));
	return (b_read);
}

static void	ft_strrep(char *s1, char *s2)
{
	while (*s2)
		*(s1++) = *(s2++);
	while (*s1)
		*(s1++) = '\0';
}

static int	ft_resolve_line(char **buf, char **line, int fd)
{
	int	i;

	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			*line = ft_strappend(*line, *buf, i + 1, 1);
			ft_strrep(*buf, &(*buf)[i + 1]);
			return (1);
		}
		if (!(*buf)[++i])
		{
			*line = ft_strappend(*line, *buf, i, 1);
			if (ft_read_nl(buf, fd) < 0)
				return (0);
		}
	}
	return (1);
}

char	*ft_get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			b_read;

	if (fd < 0)
		return (NULL);
	ft_init_buf(&buf);
	b_read = ft_read_nl(&buf, fd);
	line = NULL;
	if (!ft_resolve_line(&buf, &line, fd))
		return (NULL);
	if (line != NULL)
		return (line);
	buf = ft_free(buf);
	return (NULL);
}
