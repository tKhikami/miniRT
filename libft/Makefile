CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_memcmp.c \
	  ft_memchr.c \
	  ft_strncmp.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
NAME = libft.a

all: obj_file $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o ./obj/$@ -c $<

obj_file:
	$(shell mkdir -p obj)

$(NAME): $(OBJ)
	cd obj && ar rcs ../$(NAME) $?

bonus: obj_file $(OBJ) $(OBJ_BONUS)
	cd obj && ar rcs ../$(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

vpath %o obj
vpath $(OBJ) obj
vpath $(OBJ_BONUS) obj

.PHONY: all obj_file clean fclean re bonus
