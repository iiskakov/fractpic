.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

NOC=\033[0m
FRACT = -O2
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror $(FRACT)
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit 
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractlol.h
SRC_NAME = main.c controls.c scene.c calculate.c graphic.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@ 
		@echo "$(OKC) ___________________________________$(NOC)"
		@echo "$(OKC)|  Usage                            |$(NOC)"
		@echo "$(OKC)|___________________________________|$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|  ./fractol [key]                  |$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|        Supported fractals:        |$(NOC)"
		@echo "$(OKC)|     [mandelbrot] [sierpinski]     |$(NOC)"
		@echo "$(OKC)|          [julia] [cubic]          |$(NOC)"	
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|___________________________________|$(NOC)"
		@echo "$(OKC)|   You can also launch multiple    |$(NOC)"
		@echo "$(OKC)|   instances. For example:         |$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|   $(WAC)./fractol julia cubic$(OKC)           |$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)| Will launch 2 separate processes. |$(NOC)"
		@echo "$(OKC)|                                   |$(NOC)"
		@echo "$(OKC)|___________________________________|$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(WAC)FDF:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(WAC)FDF:\t\tRemoving fdf executables$(NOC)"

re: fclean all
