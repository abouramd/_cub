NAME := cub3D
DIR := mandatory/
SRC_PARS := check_content.c check_map.c check_path.c fill_data.c init.c pars.c put_err.c
SRC_RAYC := ray_casting.c event.c map_2d.c ft_move.c send_rays.c find_hit_dda.c wall_create.c drawframe.c
SRC := $(addprefix $(DIR), main.c $(addprefix pars/,$(SRC_PARS)) $(addprefix ray_casting/,$(SRC_RAYC)))
OBJ := $(SRC:.c=.o)
INC = -I libft/ -I $(DIR)include
LIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit


NAME_B := cub3D_bouns
DIR_B := bouns/
SRC_PARS_B := check_content.c check_map.c check_path.c fill_data.c init.c pars.c put_err.c
SRC_RAYC_B := ray_casting.c event.c map_2d.c ft_move.c send_rays.c find_hit_dda.c wall_create.c drawframe.c
SRC_B = $(addprefix $(DIR_B), main.c $(addprefix pars/,$(SRC_PARS_B)) $(addprefix ray_casting/,$(SRC_RAYC_B)))
SRC_B := $(SRC_B:.c=_bouns.c)
OBJ_B := $(SRC_B:.c=.o)
INC_B = -I libft/ -I $(DIR_B)include
LIB_B = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit


UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	INC = -I libft/ -I $(DIR)include -I ./minilibx-linux
	LIB = -L libft/ -lft -pthread -L ./minilibx-linux -lmlx_Linux -L /usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	INC_B = -I libft/ -I $(DIR_B)include -I ./minilibx-linux
	LIB_B = -L libft/ -lft -pthread -L ./minilibx-linux -lmlx_Linux -L /usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

CC:= cc
CFLAGS:= -fsanitize=address -g3
RM:= rm -rf

all:$(NAME)

bouns:$(NAME_B)

$(NAME):$(OBJ)
	@make bonus -C libft
	@echo "\033[1;3;34m - compile libft with the object files.\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(LIB)
	@echo "\033[1;3;32m ✅ $(NAME) is done.\033[0m"

$(NAME_B):$(OBJ_B)
	@make bonus -C libft
	@echo "\033[1;3;34m - compile libft with the object files.\033[0m"
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B) $(INC_B) $(LIB_B)
	@echo "\033[1;3;32m ✅ $(NAME_B) is done.\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c $^ -o $@ $(INC) $(INC_B)
	@echo "\033[1;3;34m - creat $@ from $<.\033[0m"

clean:
	@make clean -C libft
	@$(RM) $(OBJ) $(OBJ_B)
	@echo "\033[1;3;31m ❎ remove the object files of $(NAME) and $(NAME_B).\033[0m"

fclean:clean
	@$(RM) $(NAME) $(NAME_B)
	@rm -rf libft/libft.a
	@echo "\033[1;3;31m ❎ remove libft.a\033[0m"
	@echo "\033[1;3;31m ❎ remove $(NAME) and $(NAME_B).\033[0m"

re: fclean all
