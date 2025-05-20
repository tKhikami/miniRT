/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:55:35 by nyrandri          #+#    #+#             */
/*   Updated: 2024/02/26 16:24:20 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char c)
{
	if ((c <= 13 && c >= 9) || c == 32)
		return (1);
	else
		return (0);
}

static int	ft_negate(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

static int	ft_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		c = c - 48;
	return ((int)c);
}

int	ft_atoi(const char *nptr)
{
	int	length;
	int	i;
	int	ten;
	int	number;
	int	negate;

	i = 0;
	ten = 1;
	number = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	negate = ft_negate(nptr, &i);
	length = i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	i--;
	while (i >= length)
	{
		number = number + (ft_char_to_int(nptr[i]) * ten);
		ten = ten * 10;
		i--;
	}
	return (negate * number);
}
