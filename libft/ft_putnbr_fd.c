/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:56:35 by nyrandri          #+#    #+#             */
/*   Updated: 2024/08/08 02:48:46 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_base_fd(const char *str, \
		unsigned long long number, int fd)
{
	unsigned long long	quot;
	unsigned int		rest;
	unsigned int		base;

	base = ft_strlen(str);
	if (number != 0)
	{
		rest = number % base;
		quot = number / base;
		if (quot != 0)
			ft_print_base_fd(str, quot, fd);
		write (fd, &str[rest], 1);
	}
	else
		write(fd, "0", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0 && n != -2147483648)
	{
		write (fd, "-", 1);
		n = -n;
	}
	ft_print_base_fd("0123456789", n, fd);
}
