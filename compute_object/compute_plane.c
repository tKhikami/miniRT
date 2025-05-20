/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:10:55 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:46:36 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	self_shadow_plane(t_scene *scene, t_vector hit, t_objects *object)
{
	t_plane	*plane;
	double	to_light;
	double	to_camera;

	plane = (t_plane *)object->obj;
	to_light = scalar_product(plane->normal, \
					substraction(scene->light->sys.origine, hit));
	to_camera = scalar_product(plane->normal, \
					substraction(scene->camera->sys.origine, hit));
	if (to_light >= 0 && to_camera >= 0)
		return (0);
	else if (to_light < 0 && to_camera < 0)
		return (0);
	else
		return (1);
}

void	compute_plane(t_scene *scene, t_objects *object, t_ray ray, int *color)
{
	t_vector	hit_point;
	t_vector	lighting;
	double		intensity;
	t_plane		*plane;

	plane = (t_plane *)object->obj;
	hit_point = addition(scene->camera->sys.origine, \
					multiplication(ray.direction,
				object->attr.scalar));
	if (is_in_shadow(scene, hit_point, object))
		intensity = 0;
	else
	{
		lighting = vector_normalize(substraction(scene->light->sys.origine, \
					hit_point));
		intensity = fabs(scalar_product(object->attr.normal, lighting));
	}
	intensity = intensity * (1 - scene->ambient_light->ratio) + \
		scene->ambient_light->ratio;
	*color = compute_color(scene->ambient_light, plane->color, intensity);
}
