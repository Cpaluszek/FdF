#########################
#		VARIABLES		#
#########################

# Folders and names
NAME		:=	fdf

INC			:=	fdf.h mlx_utils.h
INC_DIR		:=	inc/

HEADERS		:= $(addprefix $(INC_DIR), $(INC))

SRC_DIR		:=	src/
SRC			:=	fdf.c \
				parse_map.c \
				draw_wireframe.c \
				project.c \
				rotate.c \
				fdf_errors.c \
				fdf_utils.c \
				mlx_utils.c \
				hooks.c \
				controls_utils.c \
				menu.c \
				colors.c \
				math_utils.c

LIBFT_A		:=	lib/libft/libft.a
LIBFT_DIR	:=	lib/libft/
LIBFT_INC	:= 	lib/libft/inc/

OBJ_DIR		:=	build/
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)%.o)

# Compiler options
CC			:=	cc
CC_FLAGS	:=	-Wextra -Werror -Wall
DEBUG_FLAG	:=	-ggdb3 -fsanitize=address

# define standard colors
_END		:=	\x1b[0m
_BOLD		:=	\x1b[1m
_UNDER		:=	\x1b[4m
_REV		:=	\x1b[7m
_GREY		:=	\x1b[30m
_RED		:=	\x1b[31m
_GREEN		:=	\x1b[32m
_YELLOW		:=	\x1b[33m
_BLUE		:=	\x1b[34m
_PURPLE		:=	\x1b[35m
_CYAN		:=	\x1b[36m
_WHITE		:=	\x1b[37m

#########################
# 	CROSS_PLATFORM		#
#########################

UNAME_S		:= $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_FLAG = -lm -L/usr/lib -lXext -lX11 -lz
		MLX_DIR	=	lib/minilibx-linux/
		MLX_A	=	lib/minilibx-linux/libmlx.a
	endif
	ifeq ($(UNAME_S),Darwin)
		MLX_DIR	=	lib/minilibx_macos/
		MLX_A	=	lib/minilibx_macos/libmlx.a
		MLX_FLAG = -lm -framework OpenGL -framework AppKit
	endif
#########################
# 		RULES			#
#########################

all: build_libft $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A) 
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAG) $(OBJ) $(LIBFT_A) $(MLX_A) $(MLX_FLAG) -o $@ 
	@echo "> FdF Done!\n"
	
# Libft Makefile
build_libft:
	@$(MAKE) -C $(LIBFT_DIR)

# MinilibX makefile
$(MLX_A): $(MLX_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@echo "> MLX Done!\n"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT_DIR) $(HEADERS) 
	@mkdir -p $(@D)
	@echo "$(_GREEN)compiling: $<$(_END)"
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAG) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

# clean commands
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re build_libft
