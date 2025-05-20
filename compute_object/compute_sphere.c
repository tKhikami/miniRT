/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:37:48 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:46:55 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	self_shadow_sphere(t_scene *scene, t_vector hit, t_objects *object)
{
	t_sphere	*sphere;
	double		to_light;
	double		to_camera;

	(void)hit;
	sphere = (t_sphere *)object->obj;
	to_camera = norme(substraction(sphere->sys.origine, \
								scene->camera->sys.origine));
	to_light = norme(substraction(sphere->sys.origine, \
							scene->light->sys.origine));
	if (to_camera > sphere->diametre / 2 && to_light <= \
		sphere->diametre / 2)
		return (1);
	else if (to_camera < sphere->diametre / 2 && to_light >= \
			sphere->diametre / 2)
		return (1);
	else
		return (0);
}

void	compute_sphere(t_scene *scene, t_objects *object, t_ray ray, int *color)
{
	t_vector	hit_point;
	t_vector	lighting;
	double		intensity;
	t_sphere	*sphere;

	sphere = (t_sphere *)object->obj;
	hit_point = addition(scene->camera->sys.origine, \
				multiplication(ray.direction,
				object->attr.scalar));
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
	*color = compute_color(scene->ambient_light, sphere->color, intensity);
}
