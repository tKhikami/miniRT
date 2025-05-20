/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:48:25 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/06 15:45:05 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_ambient_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 3)
	{
		ft_putendl_fd("Error\nInvalid ambient element number", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_double(e[1]) || !valid_vec(e[2]))
		return (ft_putendl_fd("Error\nInvalid ambient element", 2), 0);
	return (1);
}

int	invalid_ambient_range(t_ambient a)
{
	return (!p_in_range(a.ratio, 0.0, 1.0) || !p_in_range(a.color.r, 0.0, 255.0)
		|| !p_in_range(a.color.g, 0.0, 255.0)
		|| !p_in_range(a.color.b, 0.0, 255.0));
}

static int	get_ambient(char **elements, t_scene *o)
{
	t_vector	p;

	if (!valid_ambient_lineup(elements))
	{
		ft_free(elements);
		return (-1);
	}
	o->ambient_light->ratio = ft_atod(elements[1]);
	assign_vec(&p, elements[2]);
	o->ambient_light->color = (t_color){p.x, p.y, p.z};
	ft_free(elements);
	return (0);
}

int	parse_ambient(char *line, t_scene *o)
{
	char	**elements;

	if (o == NULL || o->ambient_light != NULL)
		return (ft_putendl_fd("Error\nNo more than one A", 2), -1);
	o->ambient_light = malloc(sizeof(t_ambient));
	if (o->ambient_light == NULL)
		return (-1);
	elements = ft_split(line, ' ');
	if (get_ambient(elements, o) == -1)
		return (-1);
	if (invalid_ambient_range(*o->ambient_light))
	{
		ft_putendl_fd("Error\nAmbient element out of value range", 2);
		return (-1);
	}
	return (0);
}
