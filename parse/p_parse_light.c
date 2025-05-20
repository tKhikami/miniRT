/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:31:20 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/05 17:43:10 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	valid_light_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error\nInvalid light elements number(rgb included)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1]) || !valid_double(e[2]) || !valid_vec(e[3]))
		return (ft_putendl_fd("Error\nInvalid light element", 2), 0);
	return (1);
}

static int	handling_error(void)
{
	ft_putendl_fd("Error\nLight element out of value range", 2);
	return (-1);
}

int	invalid_light_range(t_light a)
{
	return (!p_in_range(a.brightness_ratio, 0.0, 1.0)
		|| !p_in_range(a.color.r, 0.0, 255.0)
		|| !p_in_range(a.color.g, 0.0, 255.0)
		|| !p_in_range(a.color.b, 0.0, 255.0));
}

int	parse_light(char *line, t_scene *o)
{
	char		**elements;
	t_vector	p;

	if (o->light != NULL)
		return (ft_putendl_fd("Error\nNo more than one L", 2), -1);
	o->light = malloc(sizeof(t_light));
	if (o->light == NULL)
		return (-1);
	elements = ft_split(line, ' ');
	if (!valid_light_lineup(elements))
		return (ft_free(elements), -1);
	assign_vec(&o->light->sys.origine, elements[1]);
	o->light->brightness_ratio = ft_atod(elements[2]);
	assign_vec(&p, elements[3]);
	o->light->color = (t_color){p.x, p.y, p.z};
	ft_free(elements);
	if (invalid_light_range(*(o->light)))
		return (handling_error());
	return (0);
}
