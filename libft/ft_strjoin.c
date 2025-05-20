/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:55:28 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:44:39 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_len(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_cpy(char *dst, char const *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	leng_1;
	unsigned int	leng_2;
	char			*str;

	leng_1 = ft_len(s1);
	leng_2 = ft_len(s2);
	str = malloc(leng_1 + leng_2 + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		ft_cpy(&str[0], s1);
		ft_cpy(&str[leng_1], s2);
		str[leng_1 + leng_2] = '\0';
	}
	return (str);
}
