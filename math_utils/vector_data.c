/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:17:35 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:19:00 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

double	norme(t_vector vect)
{
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}

double	scalar_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vector_normalize(t_vector vect)
{
	double		value;
	t_vector	ret;

	value = norme(vect);
	ret.x = vect.x / value;
	ret.y = vect.y / value;
	ret.z = vect.z / value;
	return (ret);
}
