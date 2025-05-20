/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:47:44 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:43:54 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
