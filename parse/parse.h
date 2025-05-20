/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:07:56 by arajaona          #+#    #+#             */
/*   Updated: 2025/05/05 17:41:54 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../header.h"
# include "../libft/libft.h"
# include "../struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

void	assign_vec(t_point *p, char *s);
void	ft_free(char **tab);
void	ft_free_objects(t_objects *o);
int		p_in_range(double value, double inf, double max);
void	p_error(char *s);
int		parse_camera(char *s, t_scene *o);
int		p_vec(char *s, int *i, t_point *o, char *bloc);
int		parse_cylinder(char *line, t_scene *o);
int		parse_light(char *line, t_scene *o);
int		parse_ambient(char *s, t_scene *o);
int		p_double(char *s, int *i, double *o, char *err);
int		parse_plane(char *line, t_scene *o);
int		parse_sphere(char *line, t_scene *o);
int		valid_double(char *s);
int		valid_vec(char *s);
double	ft_atod(char *s);
int		parse_call(char *line, int i, t_scene *scene);
void	check_emptiness(t_data *data);
void	file_check(int ac, char *filename, t_data *data);

#endif
