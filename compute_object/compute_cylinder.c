/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:05:30 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:46:11 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	self_shadow_cylinder(t_scene *scene, t_vector hit, t_objects *object)
{
	t_vector	light_dir;	
	t_vector	light_origin;

	light_origin = scene->light->sys.origine;
	light_dir = vector_normalize(substraction(light_origin, hit));
	if (scalar_product(object->attr.normal, light_dir) <= 1e-6)
		return (1);
	return (0);
}

void	compute_cylinder(t_scene *scene, t_objects *object, \
							t_ray ray, int *color)
{
	t_vector	hit_point;
	t_vector	lighting;
	double		intensity;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)object->obj;
	hit_point = addition(scene->camera->sys.origine, \
							multiplication(ray.direction, object->attr.scalar));
	if (is_in_shadow(scene, hit_point, object))
		intensity = 0;
	else
	{
		lighting = vector_normalize(substraction(scene->light->sys.origine, \
					hit_point));
		intensity = fmax(0, scalar_product(object->attr.normal, lighting));
	}
	intensity = intensity * (1 - scene->ambient_light->ratio) + \
				scene->ambient_light->ratio;
	*color = compute_color(scene->ambient_light, cylinder->color, intensity);
}
