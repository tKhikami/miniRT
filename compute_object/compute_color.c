/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:21:29 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 12:22:26 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	compute_color(t_ambient *a_light, t_color color, double intensity)
{
	t_color	c;

	c.r = (int)(color.r * intensity + a_light->color.r * a_light->ratio);
	c.g = (int)(color.g * intensity + a_light->color.g * a_light->ratio);
	c.b = (int)(color.b * intensity + a_light->color.b * a_light->ratio);
	if (c.r > 255)
		c.r = 255;
	if (c.g > 255)
		c.g = 255;
	if (c.b > 255)
		c.b = 255;
	return ((c.r << 16) | (c.g << 8) | c.b);
}
