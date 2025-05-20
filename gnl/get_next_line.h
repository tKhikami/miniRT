/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:02 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:59:29 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_dt
{
	int		*nb;
	int		*fld;
	int		*cursor;
	int		*byteread;
	char	*buffer;
}				t_dt;

char	*get_next_line(int fd);
char	*ft_subtab(char *str, char *buffer, int str_len, int buf_len);
int		ft_poschr(const char *s, int len);

#endif
