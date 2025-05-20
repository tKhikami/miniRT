/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:45:20 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:40:03 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "struct.h"
#include <fcntl.h>

void	render(t_data *data)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < LENGTH_WIN)
	{
		x = -1;
		while (++x < WIDTH_WIN)
		{
			color = 0;
			compute_pixel(x, y, data, &color);
			my_mlx_pixel_put(&data->image, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
}

int	main(int n, char *vector[])
{
	t_data		data;

	if (n != 2)
		return (-1);
	if (init_data(&data) == -1)
		return (1);
	parse(n, vector[1], data.scene, &data);
	event(&data);
	render(&data);
	mlx_loop(data.mlx);
	destroy_data(&data);
	return (0);
}
