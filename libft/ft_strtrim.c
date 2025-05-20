/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:19:11 by nyrandri          #+#    #+#             */
/*   Updated: 2024/03/10 09:53:02 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_checkset(char const c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_checking(char const *s, char const *set, int *end, int *first)
{
	while (ft_checkset(s[*first], set) == 1)
	{
		if (*first == *end)
			break ;
		(*first)++;
	}
	while (ft_checkset(s[*end - 1], set) == 1)
	{
		if (*end == *first)
			break ;
		(*end)--;
	}
}

static unsigned int	ft_len(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_cpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				end;
	int				first;
	char			*str;

	first = 0;
	end = ft_len(s1);
	ft_checking(s1, set, &end, &first);
	str = malloc(end - first + 1);
	if (str == NULL)
		return (NULL);
	ft_cpy(str, &s1[first], end - first);
	return (str);
}
