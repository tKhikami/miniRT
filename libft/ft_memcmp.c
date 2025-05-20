/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:27:36 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:24:49 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	size_t				i;

	i = 0;
	p_s1 = s1;
	p_s2 = s2;
	while (i < n)
	{
		if (p_s1[i] == p_s2[i])
			i++;
		else
			return (p_s1[i] - p_s2[i]);
	}
	return (0);
}
