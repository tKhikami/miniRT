CC = cc
LIBFT = ../libft
LIB_PATH = minilibx-linux
FLAGS = -Wall -Wextra -Werror

FLAGS_= -I$(LIB_PATH) \
		-L$(LIB_PATH) \
		-lmlx -lmlx_Linux \
		-L/usr/lib \
		-lXext -lX11 -lm -lz \
		-L$(LIBFT) -lft 

NAME = miniRT

SRC = main.c \
	  color.c \
	  init_data.c \
	  destroy_data.c \
	  euler_angles.c \
	  vector_operations.c \
	  vector_data.c \
	  event.c \
	  compute_sphere.c \
	  compute_cylinder.c \
	  compute_plane.c \
	  compute_color.c \
	  compute_pixel.c \
	  shadow.c \
	  intersection_sphere.c \
	  intersection_cylinder.c \
	  intersection_cylinder_utils.c \
	  intersection_plane.c \
	  camera.c \
	  assign_vec.c \
	  ft_free.c \
	  p_parse_camera.c \
	  p_parse_ambient.c \
	  p_parse_light.c \
	  p_parse_sphere.c \
	  p_parse_plane.c \
	  p_parse_cylinder.c \
	  miniRT_parser.c \
	  miniRT_parser_utils.c \
	  ft_atod.c \
	  valid_element.c \
	  get_next_line_utils.c \
	  get_next_line.c \
	  zoom.c \
	  mouse.c \
	  rotation.c \
	  translation.c \
	  selection.c \
	  key.c

OBJ = $(SRC:.c=.o)

################### VARIABLE ##########################

all: libmlx.a object_file libft.a $(NAME)

object_file:
	$(shell mkdir -p obj/)

minilibx-linux :
	$(shell tar -xf minilibx-linux.tgz)

libmlx.a: minilibx-linux
	@$(MAKE) --no-print-directory -C $(LIB_PATH)

libft.a :
	@make bonus --no-print-directory -C libft/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o obj/$@

$(NAME): $(OBJ)
	cd obj && $(CC) $(OBJ) -o ../$(NAME) $(FLAGS) $(FLAGS_) -L../$(LIB_PATH) -I../$(LIB_PATH) 

clean:
	@make clean --no-print-directory -C libft/
	rm -Rf obj

fclean: clean
	@make fclean --no-print-directory -C libft/
	@rm -rf $(LIB_PATH)
	@rm -f $(NAME)

list:
	@ls -l *.c

norm: fclean
	@norminette

re: fclean all

vpath %.o obj

vpath %.c math_utils
vpath %.c compute_object
vpath %.c intersection_object
vpath %.c parse
vpath %.c gnl

vpath libft.a libft
vpath libmlx.a $(LIB_PATH)
vpath $(OBJ) obj

.PHONY: all clean fclean re object_file minilibx norm list
