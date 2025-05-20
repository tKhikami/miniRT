/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:49:57 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:46:37 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			s_len;

	s_len = ft_strlen(s);
	str = malloc(s_len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[s_len] = '\0';
	return (str);
}
