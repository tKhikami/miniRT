/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:05:45 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/15 13:43:38 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_plane_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error\nInvalid plane elements number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1]) || !valid_vec(e[2]) || !valid_vec(e[3]))
		return (ft_putendl_fd("Error\nInvalid plane element(2)", 2), 0);
	return (1);
}

int	construct_plane(t_plane *pl, char **elements)
{
	t_vector	p;

	if (!valid_plane_lineup(elements))
		return (ft_free(elements), -1);
	assign_vec(&pl->pt, elements[1]);
	assign_vec(&pl->normal, elements[2]);
	assign_vec(&p, elements[3]);
	ft_free(elements);
	if (norme(pl->normal) != 1)
	{
		ft_putendl_fd("Error\nExpected plane normal vector is not normalized",
			2);
		return (-1);
	}
	if (!p_in_range(p.x, 0.0, 255.0) || !p_in_range(p.y, 0.0, 255.0)
		|| !p_in_range(p.z, 0.0, 255.0)
		|| !p_in_range(pl->normal.x, -1.0, 1.0)
		|| !p_in_range(pl->normal.y, -1.0, 1.0)
		|| !p_in_range(pl->normal.z, -1.0, 1.0))
		return (ft_putendl_fd("Error\nPlane element out of value range", 2),
			-1);
	pl->color = (t_color){p.x, p.y, p.z};
	return (0);
}

static int	init_failure_pl(t_plane *pl, t_objects *tmp)
{
	free(pl);
	free(tmp);
	return (-1);
}

int	parse_plane(char *line, t_scene *o)
{
	t_plane		*pl;
	t_objects	*tmp;
	char		**elements;

	pl = malloc(sizeof(t_plane));
	tmp = malloc(sizeof(t_objects));
	if (pl == NULL || tmp == NULL)
		return (init_failure_pl(pl, tmp));
	tmp->type = PLANE;
	tmp->obj = pl;
	elements = ft_split(line, ' ');
	if (elements == NULL)
	{
		object_free(tmp);
		return (-1);
	}
	if (construct_plane(pl, elements))
	{
		object_free(tmp);
		return (-1);
	}
	ft_lstadd_back(&o->lst, ft_lstnew(tmp));
	return (0);
}
