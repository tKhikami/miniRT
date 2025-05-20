/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:15:26 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:15:58 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

void	zoom_camera(int button, int x, int y, t_data *data)
{
	t_vector	ray_direction;
	int			scale;

	scale = 20;
	ray_direction = get_equation_o(data->scene->camera, x, y);
	ray_direction = vector_normalize(ray_direction);
	if (button == 5)
		scale = scale * -1;
	data->scene->camera->sys.origine.x += ray_direction.x * scale;
	data->scene->camera->sys.origine.y += ray_direction.y * scale;
	data->scene->camera->sys.origine.z += ray_direction.z * scale;
	render(data);
}
