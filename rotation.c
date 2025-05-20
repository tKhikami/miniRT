/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:25:26 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:50:30 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

t_vector	*get_vect_to_rotate(t_data *data)
{
	t_vector	*vect;

	if (data->to_move == NULL)
		return (NULL);
	if (data->to_move->type == CYLINDER)
		vect = &((t_cylinder *)(data->to_move)->obj)->normal;
	else if (data->to_move->type == PLANE)
		vect = &((t_plane *)(data->to_move)->obj)->normal;
	else if (data->to_move->type == CAMERA)
		vect = &((t_camera *)(data->to_move)->obj)->normal;
	else
		return (NULL);
	return (vect);
}

void	rotation_object(int keycode, t_data *data)
{
	t_vector	*vect;

	vect = get_vect_to_rotate(data);
	if (vect == NULL)
		return ;
	if (keycode == 65436)
		*vect = x_rotation(0.0174533 * -15, *vect);
	else if (keycode == 65433)
		*vect = x_rotation(0.0174533 * 15, *vect);
	else if (keycode == 65430)
		*vect = y_rotation(0.0174533 * -15, *vect);
	else if (keycode == 65437)
		*vect = y_rotation(0.0174533 * 15, *vect);
	else if (keycode == 65429)
		*vect = z_rotation(0.0174533 * -15, *vect);
	else if (keycode == 65431)
		*vect = z_rotation(0.0174533 * 15, *vect);
	if (data->to_move->type == CAMERA)
	{
		((t_camera *)(data->to_move->obj))->teta = get_teta(*vect);
		((t_camera *)(data->to_move->obj))->phi = get_phi(*vect);
	}
	render(data);
}
