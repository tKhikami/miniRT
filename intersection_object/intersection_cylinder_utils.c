/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:37:37 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:51:09 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	valid_discriminant(t_ray ray, t_cylinder cyl, double t[])
{
	t_vector	perp[2];
	double		a;
	double		b;
	double		c;

	perp[0] = perpendicular(ray.direction, cyl.normal);
	perp[1] = perpendicular(substraction(ray.origin, cyl.center), cyl.normal);
	a = scalar_product(perp[0], perp[0]);
	b = 2 * scalar_product(perp[0], perp[1]);
	c = scalar_product(perp[1], perp[1]) - pow(cyl.diametre / 2, 2);
	if ((b * b - 4 * a * c) < 0)
		return (0);
	t[0] = (-b - sqrt(b * b -4 * a * c)) / (2 * a);
	t[1] = (-b + sqrt(b * b -4 * a * c)) / (2 * a);
	return (1);
}
