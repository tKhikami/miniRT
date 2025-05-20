/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:27:13 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:57:30 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_nbleng(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static char	*ft_init(int n, int *mark, int *sign, unsigned int *leng)
{
	char	*str;

	*sign = ft_sign(n);
	*leng = ft_nbleng(n);
	if (*sign >= 0)
	{
		str = malloc(*leng + 1);
		if (str == NULL)
			return (str);
		str[*leng] = '\0';
		*mark = 0;
		return (str);
	}
	else
	{
		str = malloc(*leng + 2);
		if (str == NULL)
			return (str);
		str[*leng + 1] = '\0';
		str[0] = '-';
		*mark = 1;
		return (str);
	}
}

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);
	else
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				sign;
	unsigned int	leng;
	int				mark;
	int				i;

	str = ft_init(n, &mark, &sign, &leng);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str = ft_zero();
		return (str);
	}
	i = leng + mark - 1;
	while (i >= mark)
	{
		str[i] = '0' + (n % 10) * sign;
		n = n / 10;
		i--;
	}
	return (str);
}
