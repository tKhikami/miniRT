/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:25:31 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/20 12:49:16 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	sub_valid_vec(char *s, int *i, int *dot_count)
{
	if ((s[*i] == '-' || s[*i] == '+') && ft_isdigit(s[*i + 1]))
		(*i)++;
	if (!ft_isdigit(s[*i]))
	{
		if (s[*i] == '.' && ft_isdigit(s[*i + 1]))
		{
			if (++(*dot_count) > 1)
				return (1);
			(*i)++;
		}
		else
			return (1);
	}
	return (0);
}

int	valid_vec(char *s)
{
	int	i;
	int	n;
	int	count;
	int	dot_count;

	count = -1;
	i = -1;
	while (++count < 3)
	{
		dot_count = 0;
		while (s[++i] && s[i] != ',' && s[i] != '\n')
		{
			n = sub_valid_vec(s, &i, &dot_count);
			if (n > 0)
				return (0);
		}
		if ((s[i] == ',' && i - 1 > 0 && !ft_isdigit(s[i - 1])) || (i == 0 && s[i] == ','))
			return (0);
		if (!s[i] || s[i] == '\n')
			break ;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	valid_double(char *s)
{
	int	i;
	int	dot_count;

	i = -1;
	dot_count = 0;
	while (s[++i] && s[i] != '\n')
	{
		if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
			i++;
		if (!ft_isdigit(s[i]))
		{
			if (s[i] == '.' && ft_isdigit(s[i + 1]))
			{
				if (++dot_count > 1)
					return (0);
				i++;
			}
			else
				return (0);
		}
	}
	return (1);
}
