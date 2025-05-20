/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:23:48 by nyrandri          #+#    #+#             */
/*   Updated: 2024/06/29 08:52:37 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** creat new info **/
char	*ft_new_fd(int fd)
{
	char	*str;
	size_t	size;
	int		val;

	if (fd == -1)
		return (NULL);
	size = sizeof(int);
	str = ft_calloc((4 * size) + BUFFER_SIZE, 1);
	if (str == NULL)
		return (NULL);
	val = 1;
	ft_memcpy(&str[0], &val, size);
	ft_memcpy(&str[size], &fd, size);
	val = 0;
	ft_memcpy(&str[(size * 2)], &val, size);
	ft_memcpy(&str[(size * 3)], &val, size);
	return (str);
}

char	*ft_get_line(char **stock, t_dt dt, int s_len)
{
	char	*str;
	int		buf_len;

	str = ft_calloc(1, 1);
	if (str == NULL)
		return (free(str), free(*stock), *stock = NULL, NULL);
	while (s_len == 0 || (s_len != buf_len + s_len && str[s_len - 1] != '\n'))
	{
		if (*dt.byteread <= *dt.cursor)
		{
			*(dt.byteread) = read(*(dt.fld), dt.buffer, BUFFER_SIZE);
			*(dt.cursor) = 0;
			if (*dt.byteread <= 0 && s_len == 0)
				return (free(str), free(*stock), *stock = NULL, NULL);
		}
		buf_len = *(dt.byteread) - *(dt.cursor);
		buf_len = ft_poschr(&dt.buffer[*(dt.cursor)], buf_len);
		str = ft_subtab(str, dt.buffer + *(dt.cursor), s_len, buf_len);
		*(dt.cursor) += buf_len;
		s_len += buf_len;
	}
	if (s_len == 0 && buf_len == 0)
		return (free(str), free(*stock), *stock = NULL, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	t_dt		dt;

	if (stock == NULL)
	{
		stock = ft_new_fd(fd);
		if (stock == NULL)
			return (NULL);
	}
	dt.nb = (int *)(&stock[0]);
	dt.fld = (int *)(&stock[sizeof(int)]);
	dt.cursor = (int *)(&stock[sizeof(int) * 2]);
	dt.byteread = (int *)(&stock[sizeof(int) * 3]);
	dt.buffer = &stock[sizeof(int) * 4];
	return (ft_get_line(&stock, dt, 0));
}
