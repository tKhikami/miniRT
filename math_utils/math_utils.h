/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:18:07 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 13:31:26 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H

# define MATH_UTILS_H

# include <math.h>
# include "../struct.h"
# include <limits.h>

double		norme(t_vector vect);
double		scalar_product(t_vector a, t_vector b);
t_vector	substraction(t_vector a, t_vector b);
t_vector	addition(t_vector a, t_vector b);
t_vector	multiplication(t_vector a, double param);
t_vector	vector_normalize(t_vector vect);
double		get_phi(t_vector vect);
double		get_teta(t_vector vect);
t_vector	z_rotation(double angle, t_vector vect);
t_vector	x_rotation(double angle, t_vector vect);
t_vector	y_rotation(double angle, t_vector vect);
double		scalar_product(t_vector a, t_vector b);

#endif
