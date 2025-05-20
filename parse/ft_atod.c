/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:09:49 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/05 17:55:01 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "parse.h"

static void	first_step(char *s, int *i)
{
	while (s && s[i[0]] && s[i[0]] == ' ')
		i[0]++;
	i[1] = i[0];
}

static void	second_step(char *s, int *i, int *count, double *val)
{
	if (s[i[0]] == '-' || s[i[0]] == '+')
	{
		i[1] = i[0];
		i[0]++;
	}
	while (ft_isdigit(s[i[0]]))
	{
		val[1] = val[1] * 10 + s[i[0]] - '0';
		i[0]++;
	}
	if (s[i[0]] == '.')
	{
		while (s[++(i[0])] && ft_isdigit(s[i[0]]))
		{
			val[0] = val[0] * 10 + s[i[0]] - '0';
			(*count)++;
		}
	}
}

double	ft_atod(char *s)
{
	int		i[2];
	double	val[2];
	int		count;

	i[0] = 0;
	count = 0;
	val[0] = 0.0;
	val[1] = 0.0;
	first_step(s, i);
	if (!s || ((s[i[0]] == '-' || s[i[0]] == '+' ) && !ft_isdigit(s[i[0] + 1])))
		return (0);
	second_step(s, i, &count, val);
	if (s[i[1]] == '-')
		return (-(val[1] + val[0] / pow(10, count)));
	return (val[1] + val[0] / pow(10, count));
}
