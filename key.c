/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:55:37 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:57:00 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

static void	extended_change_property(t_data *data, int n, double *cmp)
{
	if (n >= 0 || *cmp > -n)
	{
		if (*cmp < INT_MAX / 4 - n)
		{
			*cmp += n;
			render(data);
		}
	}
}

void	change_property(t_data *data, int n, int mode)
{
	if (data->to_move == NULL)
		return ;
	else if (data->to_move->type == SPHERE)
	{
		if (mode == 0)
			extended_change_property(data, n,
				&((t_sphere *)data->to_move->obj)->diametre);
	}
	else if (data->to_move->type == CYLINDER)
	{
		if (mode == 0)
			extended_change_property(data, n,
				&((t_cylinder *)data->to_move->obj)->diametre);
		if (mode == 1)
			extended_change_property(data, n,
				&((t_cylinder *)data->to_move->obj)->height);
	}
}

static void	what_translation(int keycode, t_data *data)
{
	if (keycode == 65455)
		translate_object(data, (t_vector){0, -20, 0});
	else if (keycode == 65450)
		translate_object(data, (t_vector){0, 20, 0});
	else if (keycode == 65364)
		translate_object(data, (t_vector){0, 0, -20});
	else if (keycode == 65362)
		translate_object(data, (t_vector){0, 0, 20});
	else if (keycode == 65361)
		translate_object(data, (t_vector){-20, 0, 0});
	else if (keycode == 65363)
		translate_object(data, (t_vector){20, 0, 0});
}

int	key_press(int keycode, t_data *data)
{
	static int	mode;

	if (keycode == 100 || keycode == 104)
		mode = display_mode(keycode);
	if (keycode == 99 || keycode == 108)
		select_object(keycode, data);
	else if (keycode == 65436 || keycode == 65433 || keycode == 65430
		|| keycode == 65437 || keycode == 65429 || keycode == 65431)
		rotation_object(keycode, data);
	else if (keycode == 65451)
		change_property(data, 5, mode);
	else if (keycode == 65453)
		change_property(data, -5, mode);
	else if (keycode == 65455 || keycode == 65450 || keycode == 65364
		|| keycode == 65362 || keycode == 65361 || keycode == 65363)
		what_translation(keycode, data);
	return (0);
}
