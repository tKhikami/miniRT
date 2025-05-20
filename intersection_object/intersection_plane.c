/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:49:32 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:51:15 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	plane_intersection(t_ray ray, t_objects *plane)
{
	double	denominator;
	t_plane	*pl;

	pl = (t_plane *)plane->obj;
	denominator = scalar_product(ray.direction, pl->normal);
	plane->attr.scalar = scalar_product(substraction(pl->pt, ray.origin),
			pl->normal) / denominator;
	if (plane->attr.scalar <= 0)
		return (0);
	plane->attr.normal = pl->normal;
	return (1);
}
