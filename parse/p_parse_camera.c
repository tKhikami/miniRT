/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:31:25 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/06 15:55:19 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_cam_lineup(char **e)
{
	int	i;

	i = 0;
	while (e[i] && e[i][0] != '\n')
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error\nInvalid camera elements number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error\n", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1]) || !valid_vec(e[2]) || !valid_double(e[3]))
		return (ft_putendl_fd("Error\nInvalid camera element(2)", 2), 0);
	return (1);
}

static void	assign_step(t_scene *o, char **elements)
{
	assign_vec(&o->camera->sys.origine, elements[1]);
	assign_vec(&o->camera->normal, elements[2]);
	o->camera->fov = ft_atod(elements[3]);
}

int	element_check(t_vector normal, int fov)
{
	if (norme(normal) != 1)
	{
		ft_putendl_fd("Error\nExpected camera normal vector not normalized",
			2);
		return (-1);
	}
	if (!p_in_range(normal.x, -1.0, 1.0)
		|| !p_in_range(normal.y, -1.0, 1.0)
		|| !p_in_range(normal.z, -1.0, 1.0)
		|| !p_in_range(fov, 0.0, 180.0))
	{
		ft_putendl_fd("Error\nCamera element out of value range", 2);
		return (-1);
	}
	return (0);
}

int	parse_camera(char *line, t_scene *o)
{
	char	**elements;

	if (o->camera != NULL)
		return (ft_putendl_fd("Error\nNo more than one C", 2), -1);
	o->camera = malloc(sizeof(t_camera));
	if (o->camera == NULL)
		return (-1);
	elements = ft_split(line, ' ');
	if (!valid_cam_lineup(elements))
		return (ft_free(elements), -1);
	assign_step(o, elements);
	ft_free(elements);
	return (element_check(o->camera->normal, o->camera->fov));
}
