/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:13:48 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:15:38 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_vector	substraction(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	addition(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	multiplication(t_vector a, double param)
{
	return ((t_vector){a.x * param, a.y * param, a.z * param});
}

t_vector	projection(t_vector v, t_vector axis)
{
	return (multiplication(axis, scalar_product(v, axis)));
}

t_vector	perpendicular(t_vector v, t_vector axis)
{
	return (substraction(v, projection(v, axis)));
}
