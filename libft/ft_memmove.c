/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:18:02 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/08 01:23:27 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		tmp;
	char		*p_dest;
	const char	*p_src;

	p_dest = dest;
	p_src = src;
	i = 0;
	while (i < n)
	{
		tmp = p_src[i];
		p_dest[i] = tmp;
		i++;
	}
	return (dest);
}
