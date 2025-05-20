/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:11:04 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/15 13:39:59 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_cylindre_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 6)
	{
		ft_putendl_fd("Error\nInvalid cylinder elements number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1]) || !valid_vec(e[2]) || !valid_double(e[3])
		|| !valid_double(e[4]) || !valid_vec(e[5]))
		return (ft_putendl_fd("Error\nInvalid cylinder element(2)", 2), 0);
	return (-1);
}

int	invalid_cylinder_e_range(t_cylinder *cy, t_vector p)
{
	return (!p_in_range(p.x, 0.0, 255.0) || !p_in_range(p.y, 0.0, 255.0)
		|| !p_in_range(p.z, 0.0, 255.0)
		|| !p_in_range(cy->normal.x, -1.0, 1.0)
		|| !p_in_range(cy->normal.y, -1.0, 1.0)
		|| !p_in_range(cy->normal.z, -1.0, 1.0)
		|| !p_in_range(cy->height, 0.1, INT_MAX / 4)
		|| !p_in_range(cy->diametre, 0.1, INT_MAX / 4));
}

int	construct_cylinder(t_cylinder *cy, char **elements)
{
	t_vector	p;

	if (!valid_cylindre_lineup(elements))
		return (ft_free(elements), -1);
	assign_vec(&cy->center, elements[1]);
	assign_vec(&cy->normal, elements[2]);
	cy->diametre = ft_atod(elements[3]);
	cy->height = ft_atod(elements[4]);
	assign_vec(&p, elements[5]);
	ft_free(elements);
	if (norme(cy->normal) != 1)
	{
		ft_putendl_fd("Error\nExpected cylinder normal vector not normalized",
			2);
		return (-1);
	}
	if (invalid_cylinder_e_range(cy, p))
		return (ft_putendl_fd("Error\nCylinder element out of value range", 2),
			-1);
	cy->color = (t_color){p.x, p.y, p.z};
	return (0);
}

static int	init_failure_cy(t_cylinder *cy, t_objects *tmp)
{
	free(cy);
	free(tmp);
	return (-1);
}

int	parse_cylinder(char *line, t_scene *o)
{
	t_objects	*tmp;
	t_cylinder	*cy;
	char		**elements;

	cy = malloc(sizeof(t_cylinder));
	tmp = malloc(sizeof(t_objects));
	if (cy == NULL || tmp == NULL)
		return (init_failure_cy(cy, tmp));
	tmp->type = CYLINDER;
	tmp->obj = cy;
	elements = ft_split(line, ' ');
	if (elements == NULL)
	{
		object_free(tmp);
		return (-1);
	}
	if (construct_cylinder(cy, elements))
	{
		object_free(tmp);
		return (-1);
	}
	ft_lstadd_back(&o->lst, ft_lstnew(tmp));
	return (0);
}
