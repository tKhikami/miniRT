/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:57:07 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:51:25 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static double	calculate_sphere_disc(t_ray ray, t_sphere sphere)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;

	oc = substraction(ray.origin, sphere.sys.origine);
	a = scalar_product(ray.direction, ray.direction);
	b = scalar_product(oc, ray.direction);
	c = scalar_product(oc, oc) - pow(sphere.diametre / 2, 2);
	return (b * b - a * c);
}

int	sphere_intersection(t_ray ray, t_objects *sphere)
{
	t_sphere	*sp;
	double		b;
	double		t[2];
	double		discriminant;
	double		a;

	sp = (t_sphere *)sphere->obj;
	discriminant = calculate_sphere_disc(ray, *sp);
	if (discriminant < 0)
		return (0);
	b = scalar_product(substraction(ray.origin, sp->sys.origine), \
					ray.direction);
	a = scalar_product(ray.direction, ray.direction);
	t[0] = ((-b - sqrt(discriminant)) / a);
	t[1] = ((-b + sqrt(discriminant)) / a);
	if (t[0] > 0)
		sphere->attr.scalar = t[0];
	else
		sphere->attr.scalar = t[1];
	if (sphere->attr.scalar <= 0)
		return (0);
	sphere->attr.normal = vector_normalize(substraction(addition(ray.origin,
					multiplication(ray.direction, sphere->attr.scalar)),
				sp->sys.origine));
	return (1);
}
