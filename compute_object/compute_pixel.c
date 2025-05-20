/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:59 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 12:23:34 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	compute_object(t_scene *scene, t_objects *object, t_ray ray, int *color)
{
	if (object == NULL)
		return ;
	if (object->type == SPHERE)
		compute_sphere(scene, object, ray, color);
	else if (object->type == PLANE)
		compute_plane(scene, object, ray, color);
	else if (object->type == CYLINDER)
		compute_cylinder(scene, object, ray, color);
}

int	object_intersection(t_ray ray, t_objects *object)
{
	if (object->type == SPHERE)
		object->attr.hit = sphere_intersection(ray, object);
	else if (object->type == PLANE)
		object->attr.hit = plane_intersection(ray, object);
	else if (object->type == CYLINDER)
		object->attr.hit = cylinder_intersection(ray, object);
	else
		object->attr.hit = 0;
	return (object->attr.hit);
}

t_objects	*get_nearest_object(t_ray ray, t_list *lst)
{
	t_list		*tmp;
	t_objects	*stock;

	tmp = lst;
	stock = NULL;
	while (tmp != NULL)
	{
		if (object_intersection(ray, (t_objects *)tmp->content))
		{
			if (stock == NULL)
				stock = (t_objects *)tmp->content;
			else if (((t_objects *)tmp->content)->attr.scalar < \
					stock->attr.scalar)
				stock = (t_objects *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (stock);
}

void	compute_pixel(int ndc_x, int ndc_y, t_data *data, int *color)
{
	t_ray		ray;
	t_objects	*stock;

	ray.direction = vector_normalize(get_equation_o(\
						data->scene->camera, ndc_x, ndc_y));
	ray.origin = data->scene->camera->sys.origine;
	stock = get_nearest_object(ray, data->scene->lst);
	if (stock == NULL)
		return ;
	compute_object(data->scene, stock, ray, color);
}
