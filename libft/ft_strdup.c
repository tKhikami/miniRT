/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:13:39 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:43:33 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_leng(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		leng;
	int		i;

	i = 0;
	leng = ft_leng(s);
	str = malloc(leng + 1);
	while (i < leng)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
