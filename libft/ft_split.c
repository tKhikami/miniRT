/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 07:09:32 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 10:54:08 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tab(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while ((s[i] != '\0') && (s[i] != c))
				i++;
		}
	}
	return (n);
}

static char	*ft_get_word(char const *s, char c)
{
	size_t	n;
	char	*word;

	n = 0;
	while ((s[n] != '\0') && (s[n] != c))
		n++;
	word = ft_substr(s, 0, n);
	if (word == NULL)
		return (NULL);
	return (word);
}

static char	**ft_get_words(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;

	words = (char **) malloc((ft_wcount(s, c) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words[j] = ft_get_word((s + i), c);
			if (words[j] == NULL)
				return (free_tab(words));
			i += ft_strlen(words[j]);
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = ft_get_words(s, c);
	return (split);
}
