/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:23:41 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 12:24:12 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_in_self_shadow(t_scene *scene, t_vector hit, t_objects *object)
{
	if (object->type == SPHERE)
		return (self_shadow_sphere(scene, hit, object));
	else if (object->type == PLANE)
		return (self_shadow_plane(scene, hit, object));
	else
		return (0);
}

int	is_in_shadow(t_scene *scene, t_vector hit, t_objects *object)
{
	t_vector	to_light;
	t_ray		shadow_ray;
	t_list		*tmp;
	double		normal;

	if (is_in_self_shadow(scene, hit, object))
		return (1);
	to_light = substraction(scene->light->sys.origine, hit);
	normal = norme(to_light);
	shadow_ray.direction = vector_normalize(to_light);
	shadow_ray.origin = addition(hit, \
						multiplication(shadow_ray.direction, 0.01));
	if (scene->lst == NULL)
		return (-1);
	tmp = scene->lst;
	while (tmp != NULL)
	{
		if (tmp->content != (void *)object)
			if (object_intersection(shadow_ray, (t_objects *)tmp->content))
				if (((t_objects *)tmp->content)->attr.scalar < normal)
					return (1);
		tmp = tmp->next;
	}
	return (0);
}
