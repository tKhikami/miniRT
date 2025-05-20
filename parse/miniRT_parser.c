/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:01:37 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/15 13:49:32 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "parse.h"

static void	final_step_parse(int fd, t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	close(fd);
	check_emptiness(data);
	scene->camera->focal_distance = (long long int)(WIDTH_WIN / (2
				* tan(scene->camera->fov * 0.0174533 / 2.0)));
	scene->camera->teta = get_teta(scene->camera->normal);
	scene->camera->phi = get_phi(scene->camera->normal);
}

static void	fetch_command(char **line, int fd, t_scene *scene, t_data *data)
{
	int	i;

	i = 0;
	while ((*line)[i] && (*line)[i] == 32 && (*line)[i] != '\n')
		i++;
	if (parse_call(*line, i, scene))
	{
		free(*line);
		while (*line != NULL)
		{
			*line = get_next_line(fd);
			free(*line);
		}
		close(fd);
		destroy_data(data);
		exit(1);
	}
	free(*line);
	*line = get_next_line(fd);
}

void	parse(int ac, char *filename, t_scene *scene, t_data *data)
{
	int		fd;
	char	*line;

	file_check(ac, filename, data);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror(filename);
		destroy_data(data);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
		fetch_command(&line, fd, scene, data);
	final_step_parse(fd, data);
	free(line);
}
