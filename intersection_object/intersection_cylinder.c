/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:41:05 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/04 14:51:02 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_cylinder(t_ray ray, t_objects *cylinder, \
						t_vector vect[], double t[])
{
	t_cylinder	*cy;

	cy = (t_cylinder *)cylinder->obj;
	vect[0] = addition(ray.origin, \
					multiplication(ray.direction, cylinder->attr.scalar));
	vect[1] = substraction(vect[0], cy->center);
	t[2] = scalar_product(vect[1], cy->normal);
}

int	body_intersection(t_ray ray, t_objects *cylinder)
{
	t_cylinder	*cy;
	t_vector	vect[2];
	double		t[3];
	int			i;

	i = -1;
	cy = (t_cylinder *)cylinder->obj;
	if (!valid_discriminant(ray, *cy, t))
		return (0);
	while (++i < 2)
	{
		cylinder->attr.scalar = t[i];
		init_cylinder(ray, cylinder, vect, t);
		if (t[i] >= 0)
		{
			if (fabs(t[2]) <= cy->height / 2)
			{
				cylinder->attr.normal = \
					vector_normalize(perpendicular(vect[1], cy->normal));
				return (1);
			}
		}
	}
	cylinder->attr.scalar = -1;
	return (0);
}

void	put_cap(t_ray ray, t_objects *cylinder, t_cyl_helper h)
{
	t_cylinder		*cy;
	t_vector		hit_point;

	cy = (t_cylinder *)cylinder->obj;
	hit_point = addition(ray.origin, multiplication(ray.direction, h.t));
	if (norme(substraction(hit_point, h.cap_center)) <= cy->diametre / 2)
	{
		if (cylinder->attr.scalar < 0 || h.t < cylinder->attr.scalar)
		{
			cylinder->attr.scalar = h.t;
			if (!h.i)
				cylinder->attr.normal = cy->normal;
			else
				cylinder->attr.normal = multiplication(cy->normal, -1);
		}
	}
}

int	cap_intersection(t_ray ray, t_objects *cylinder)
{
	t_cylinder		*cy;
	t_cyl_helper	medium;

	cy = (t_cylinder *)cylinder->obj;
	medium.i = -1;
	while (++medium.i < 2)
	{
		if (!medium.i)
			medium.cap_center = addition(cy->center, \
			multiplication(cy->normal, cy->height / 2));
		else
			medium.cap_center = addition(cy->center, \
			multiplication(cy->normal, -cy->height / 2));
		medium.t = scalar_product(substraction(medium.cap_center, \
									ray.origin), cy->normal) / \
			scalar_product(ray.direction, cy->normal);
		if (medium.t > 0)
			put_cap(ray, cylinder, medium);
	}
	if (cylinder->attr.scalar < 0)
		return (0);
	return (1);
}

int	cylinder_intersection(t_ray ray, t_objects *cylinder)
{
	t_cylinder	*cy;
	int			hit;

	cy = (t_cylinder *)cylinder->obj;
	hit = 0;
	cylinder->attr.scalar = -1;
	cy->normal = vector_normalize(cy->normal);
	hit |= body_intersection(ray, cylinder);
	hit |= cap_intersection(ray, cylinder);
	cylinder->type = CYLINDER;
	return (hit);
}
