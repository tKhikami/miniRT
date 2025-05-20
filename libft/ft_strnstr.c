/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:24:37 by nyrandri          #+#    #+#             */
/*   Updated: 2024/03/10 09:14:46 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0' && len == 0)
		return ((char *)big);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[j + i] != '\0' && i + j < len)
		{
			if (little[j] != big[j + i])
				break ;
			else
				j++;
		}
		if (little[j] == '\0')
			return (&((char *)big)[i]);
		if (big[j + i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
