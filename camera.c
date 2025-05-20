/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:31:39 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 14:48:27 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector	get_equation_c(t_camera *cam, int i, int j)
{
	t_vector	director;

	director.x = i - WIDTH_WIN / 2.0;
	director.y = cam->focal_distance;
	director.z = LENGTH_WIN / 2.0 - j;
	return (director);
}

t_vector	get_equation_o(t_camera *cam, int i, int j)
{
	t_vector	director;

	director = get_equation_c(cam, i, j);
	director = x_rotation(cam->teta, director);
	director = z_rotation(-1 * cam->phi, director);
	return (director);
}

t_vector	base_change(t_data *data, t_vector vect)
{
	t_vector	ret;

	ret = x_rotation(data->scene->camera->teta, vect);
	ret = z_rotation(-data->scene->camera->phi, ret);
	return (ret);
}
