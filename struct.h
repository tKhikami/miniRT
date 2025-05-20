/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:02:56 by nyrandri          #+#    #+#             */
/*   Updated: 2025/05/04 11:15:04 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include "libft/libft.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		end;
}	t_image;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef t_point	t_vector;

typedef struct s_cartesian_coordinate
{
	t_point	origine;
	int		i;
	int		j;
	int		k;
}	t_cartesian_coordinate;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_obj_attr
{
	int			hit;
	double		scalar;
	t_vector	normal;
}	t_obj_attr;

typedef struct s_camera
{
	t_cartesian_coordinate	sys; // par rapport a la referentielle absolue
	int						fov;
	long long int			focal_distance;
	t_vector				normal;
	double					phi;
	double					teta;
}	t_camera;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_light
{
	t_cartesian_coordinate	sys;
	t_color					color;
	double					brightness_ratio;
}	t_light;

typedef struct s_ambient
{
	float	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_sphere
{
	t_cartesian_coordinate	sys;
	double					diametre;
	t_color					color;
}	t_sphere;

typedef struct s_plane
{
	t_point		pt;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	normal;
	double		diametre;
	double		height;
	t_color		color;
}	t_cylinder;

typedef enum e_obj_type
{
	CAMERA,
	LIGHT,
	AMBIANT,
	SPHERE,
	CYLINDER,
	PLANE
}	t_obj_type;

typedef struct s_objects
{
	t_obj_type	type;
	t_obj_attr	attr;
	void		*obj;
}	t_objects;

typedef struct s_scene
{
	t_camera	*camera;
	t_light		*light;
	t_ambient	*ambient_light;
	t_list		*lst;
}	t_scene;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_image		image;
	t_scene		*scene;
	t_point		hook;
	t_objects	*to_move;
}	t_data;

typedef struct s_cyl_helper
{
	t_vector	cap_center;
	double		t;
	int			i;
}	t_cyl_helper;

#endif
