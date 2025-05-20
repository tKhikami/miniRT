/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:56:22 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:03 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <limits.h>

int	valid_sphere_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error\nInvalid sphere elements number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1]) || !valid_double(e[2]) || !valid_vec(e[3]))
		return (ft_putendl_fd("Error\nInvalid sphere element(2)", 2), 0);
	return (1);
}

int	construct_sphere(t_sphere *sp, char **elements)
{
	t_vector	p;

	if (!valid_sphere_lineup(elements))
		return (ft_free(elements), -1);
	assign_vec(&sp->sys.origine, elements[1]);
	sp->diametre = ft_atod(elements[2]);
	assign_vec(&p, elements[3]);
	ft_free(elements);
	if (!p_in_range(p.x, 0.0, 255.0) || !p_in_range(p.y, 0.0, 255.0)
		|| !p_in_range(p.z, 0.0, 255.0)
		|| !p_in_range(sp->diametre, 0.1, INT_MAX / 4))
		return (ft_putendl_fd("Error\nSphere element out of value range", 2),
			-1);
	sp->color = (t_color){p.x, p.y, p.z};
	return (0);
}

static int	init_failure_sp(t_sphere *sp, t_objects *tmp)
{
	free(sp);
	free(tmp);
	return (-1);
}

int	parse_sphere(char *line, t_scene *o)
{
	t_sphere	*sp;
	t_objects	*tmp;
	char		**elements;

	sp = malloc(sizeof(t_sphere));
	tmp = malloc(sizeof(t_objects));
	if (sp == NULL || tmp == NULL)
		return (init_failure_sp(sp, tmp));
	tmp->type = SPHERE;
	tmp->obj = sp;
	elements = ft_split(line, ' ');
	if (elements == NULL)
	{
		object_free(tmp);
		return (-1);
	}
	if (construct_sphere(sp, elements))
	{
		object_free(tmp);
		return (-1);
	}
	ft_lstadd_back(&o->lst, ft_lstnew(tmp));
	return (0);
}
