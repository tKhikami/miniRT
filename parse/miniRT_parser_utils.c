/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:08 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/07 10:02:27 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	p_error(char *s)
{
	ft_putstr_fd("error in parsing ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(" elements", 2);
}

int	p_in_range(double value, double inf, double max)
{
	if (value >= round(inf) && value <= round(max))
		return (1);
	return (0);
}

void	file_check(int ac, char *filename, t_data *data)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		ft_putendl_fd("Error\nWrong number of arguments !", 2);
		exit(1);
	}
	while (filename[i])
		i++;
	if (ft_strncmp(&filename[i - 3], ".rt", 3))
	{
		ft_putendl_fd("Error\nFile has to be suffixed .rt", 2);
		destroy_data(data);
		exit(1);
	}
}

void	check_emptiness(t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	if (!scene->camera || !scene->light || !scene->ambient_light)
	{
		destroy_data(data);
		ft_putendl_fd("Error\nMissing identifier", 2);
		exit(1);
	}
}

int	parse_call(char *line, int i, t_scene *scene)
{
	int	ret;

	if (line[i] == 'A')
		ret = parse_ambient(line, scene);
	else if (line[i] == 'C')
		ret = parse_camera(line, scene);
	else if (line[i] == 'L')
		ret = parse_light(line, scene);
	else if (!ft_strncmp(&line[i], "sp", 2))
		ret = parse_sphere(line, scene);
	else if (!ft_strncmp(&line[i], "pl", 2))
		ret = parse_plane(line, scene);
	else if (!ft_strncmp(&line[i], "cy", 2))
		ret = parse_cylinder(line, scene);
	else if (!line[i] || line[i] == '\n')
		ret = 0;
	else
	{
		ft_putendl_fd("Error\nFound unexpected identifier", 2);
		ret = -1;
	}
	return (ret);
}
