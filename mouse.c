/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:18:49 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:48:39 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

static void	move_objects(t_objects *object, t_vector vect)
{
	t_point	*pt;

	pt = NULL;
	if (object == NULL)
		return ;
	if (object->type == SPHERE)
		pt = &((t_sphere *)object->obj)->sys.origine;
	else if (object->type == PLANE)
		pt = &((t_plane *)object->obj)->pt;
	else if (object->type == CAMERA)
		pt = &((t_camera *)object->obj)->sys.origine;
	else if (object->type == CYLINDER)
		pt = &((t_cylinder *)object->obj)->center;
	if (pt == NULL)
		return ;
	pt->x += vect.x;
	pt->y += vect.y;
	pt->z += vect.z;
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
		get_to_move_object(x, y, data);
	else if (button == 3)
	{
		data->hook.x = x;
		data->hook.z = y;
	}
	else if (button == 4 || button == 5)
		zoom_camera(button, x, y, data);
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	t_vector	vect;

	if (button == 1)
	{
		if (data->to_move == NULL)
			return (-1);
		vect.x = x - data->hook.x;
		vect.y = 0;
		vect.z = data->hook.z - y;
		vect = multiplication(vect, data->to_move->attr.scalar);
		vect = base_change(data, vect);
		move_objects(data->to_move, vect);
		render(data);
	}
	return (0);
}
