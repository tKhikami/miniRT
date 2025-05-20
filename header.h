/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:35:14 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/15 15:57:23 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

/*************** Include *****************/
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "struct.h"
# include "math_utils/math_utils.h"

/*************** Macro ******************/
# define WIDTH_WIN 1000
# define LENGTH_WIN 700
# define ESCAPE 65307

void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
int			init_data(t_data *data);
void		new_object(t_data *data, t_obj_type type);
void		render(t_data *data);

void		parse(int ac, char *filename, t_scene *scene, t_data *data);
void		object_free(void *ptr);
void		destroy_scene(t_scene *scene);
void		destroy_data(t_data *data);

/**************************************************/

/****************** EVENT *******************/

int			close_window(int keycode, t_data *data);
void		event(t_data *data);
void		zoom_camera(int button, int x, int y, t_data *data);
int			mouse_release(int button, int x, int y, t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);
void		rotation_object(int keycode, t_data *data);
void		translate_object(t_data *data, t_vector vect);
void		get_to_move_object(int x, int y, t_data *data);
t_vector	*get_vect_to_rotate(t_data *data);
int			select_object(int keycode, t_data *data);
int			display_mode(int keycode);
int			key_press(int keycode, t_data *data);
void		change_property(t_data *data, int n, int mode);

/****************** OBJECT ********************/

t_objects	*get_nearest_object(t_ray ray, t_list *lst);
t_vector	projection(t_vector v, t_vector axis);
t_vector	perpendicular(t_vector v, t_vector axis);

// INFO: LIGHT

t_light		*make_light(void);

// INFO: CAMERA

t_vector	get_equation_o(t_camera *cam, int i, int j);
t_vector	get_equation_c(t_camera *cam, int i, int j);
t_vector	base_change(t_data *data, t_vector vect);

// INFO: SPHERE

int			self_shadow_sphere(t_scene *scene, t_vector hit, t_objects *object);
int			sphere_intersection(t_ray ray, t_objects *sphere);
void		compute_sphere(t_scene *scene, t_objects *object, \
							t_ray ray, int *color);

// INFO: CYLINDER

int			valid_discriminant(t_ray ray, t_cylinder cyl, double t[]);
int			cylinder_intersection(t_ray ray, t_objects *cylinder);
void		compute_cylinder(t_scene *scene, t_objects *object, \
								t_ray ray, int *color);

// INFO: PLANE

int			self_shadow_plane(t_scene *scene, t_vector hit, t_objects *object);
int			plane_intersection(t_ray ray, t_objects *plane);
void		compute_plane(t_scene *scene, t_objects *object, \
							t_ray ray, int *color);

// INFO: PIXEL

void		compute_pixel(int ndc_x, int ndc_y, t_data *data, int *color);
int			compute_color(t_ambient *a_light, t_color color, double intensity);
int			is_in_shadow(t_scene *scene, t_vector hit, t_objects *object);

int			object_intersection(t_ray ray, t_objects *object);
#endif
