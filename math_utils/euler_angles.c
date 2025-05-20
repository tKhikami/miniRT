/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:17:24 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:18:03 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

double	get_teta(t_vector vect)
{
	t_vector	n;
	double		a;

	n = vector_normalize(vect);
	a = atan2(n.z, sqrt(n.x * n.x + n.y * n.y));
	return (a);
}

double	get_phi(t_vector vect)
{
	t_vector	n;
	double		b;

	n = vector_normalize(vect);
	b = atan2(n.x, n.y);
	return (b);
}

t_vector	x_rotation(double angle, t_vector vect)
{
	t_vector	ret;

	ret.x = vect.x;
	ret.y = vect.y * cos(angle) - vect.z * sin(angle);
	ret.z = vect.y * sin(angle) + vect.z * cos(angle);
	return (ret);
}

t_vector	z_rotation(double angle, t_vector vect)
{
	t_vector	ret;

	ret.x = vect.x * cos(angle) - vect.y * sin(angle);
	ret.y = vect.x * sin(angle) + vect.y * cos(angle);
	ret.z = vect.z;
	return (ret);
}

t_vector	y_rotation(double angle, t_vector vect)
{
	t_vector	ret;

	ret.x = vect.x * cos(angle) + vect.z * sin(angle);
	ret.y = vect.y;
	ret.z = -vect.x * sin(angle) + vect.z * cos(angle);
	return (ret);
}
