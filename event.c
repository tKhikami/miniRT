/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:00:17 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 16:00:30 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		mlx_loop_end(data->mlx);
	return (0);
}

void	event(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, &mlx_loop_end, data->mlx);
	mlx_key_hook(data->mlx_win, &close_window, data);
	mlx_hook(data->mlx_win, 04, 1L << 2, &mouse_press, data);
	mlx_hook(data->mlx_win, 05, 1L << 3, &mouse_release, data);
	mlx_hook(data->mlx_win, 02, 1L << 0, &key_press, data);
}
