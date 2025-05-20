/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:36:12 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:54:31 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

void	get_to_move_object(int x, int y, t_data *data)
{
	t_ray	ray;

	data->hook.x = x;
	data->hook.z = y;
	ray.origin = data->scene->camera->sys.origine;
	ray.direction = get_equation_o(data->scene->camera, x, y);
	if (data->to_move != NULL)
		if (data->to_move->type == CAMERA || data->to_move->type == LIGHT)
			free(data->to_move);
	data->to_move = get_nearest_object(ray, data->scene->lst);
	if (data->to_move == NULL)
		return ;
	if (data->to_move->type == CYLINDER)
		printf("Cylinder selected\n");
	else if (data->to_move->type == SPHERE)
		printf("Sphere selected\n");
	else if (data->to_move->type == PLANE)
		printf("Plane selected\n");
}

int	display_mode(int keycode)
{
	if (keycode == 100)
	{
		printf("Diameter mode selected\n");
		return (0);
	}
	else
	{
		printf("Height mode selected\n");
		return (1);
	}
}

int	select_object(int keycode, t_data *data)
{
	t_objects	*obj;

	if (data->to_move != NULL)
		if (data->to_move->type == CAMERA || data->to_move->type == LIGHT)
			free(data->to_move);
	obj = malloc(sizeof(t_objects));
	if (obj == NULL)
		return (-1);
	if (keycode == 99)
	{
		obj->type = CAMERA;
		obj->obj = data->scene->camera;
		data->to_move = obj;
		printf("Camera selected\n");
	}
	else if (keycode == 108)
	{
		obj->type = LIGHT;
		obj->obj = data->scene->light;
		data->to_move = obj;
		printf("Light selected\n");
	}
	return (keycode);
}
