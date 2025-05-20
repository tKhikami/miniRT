/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:31:19 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:49:41 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

void	translate_object(t_data *data, t_vector vect)
{
	double		scale;
	t_vector	*origine;

	if (data->to_move == NULL)
		return ;
	if (data->to_move->type == CYLINDER)
		origine = &((t_cylinder *)(data->to_move->obj))->center;
	else if (data->to_move->type == SPHERE)
		origine = &((t_sphere *)(data->to_move->obj))->sys.origine;
	else if (data->to_move->type == PLANE)
		origine = &((t_plane *)(data->to_move->obj))->pt;
	else if (data->to_move->type == CAMERA)
		origine = &((t_camera *)(data->to_move->obj))->sys.origine;
	else
		origine = &((t_light *)(data->to_move->obj))->sys.origine;
	scale = 10;
	vect = vector_normalize(base_change(data, vect));
	origine->x += vect.x * scale;
	origine->y += vect.y * scale;
	origine->z += vect.z * scale;
	render(data);
}
