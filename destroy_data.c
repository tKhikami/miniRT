/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:36:17 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/20 12:27:00 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	object_free(void *ptr)
{
	t_objects	*object;

	if (ptr == NULL)
		return ;
	object = (t_objects *)ptr;
	free(object->obj);
	free(ptr);
}

void	destroy_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free(scene->camera);
	free(scene->light);
	free(scene->ambient_light);
	ft_lstclear(&scene->lst, &object_free);
	free(scene);
}

void	destroy_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->to_move != NULL)
	{
		if (data->to_move->type == CAMERA)
			free(data->to_move);
		else if (data->to_move->type == LIGHT)
			free(data->to_move);
	}
	destroy_scene(data->scene);
}
