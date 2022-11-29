#########################
#		VARIABLES		#
#########################

# Folders and names
NAME		:=	fdf

INC			:=	fdf.h
INC_DIR		:=	inc/

SRC_DIR		:=	src/
SRC			:=	main.c \
				parse_map.c \
				draw_wireframe.c \
				fdf_errors.c \
				fdf_utils.c \
				mlx_utils.c

LIBFT_A		:=	libft.a
LIBFT_DIR	:=	lib/libft/
LIBFT_INC	:= 	lib/libft/inc/

MLX_DIR		:=	lib/minilibx_macos/
MLX_A		:=	libmlx.a

OBJ_DIR		:=	build/
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)%.o)

# Compiler options
CC			:=	cc
CC_FLAGS	:=	-Wextra -Werror -Wall
DEBUG_FLAG	:=	-ggdb3

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
# 		RULES			#
#########################

all: build_lib $(NAME)

$(NAME): build_lib $(OBJ)
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAG) $(OBJ) $(LIBFT_DIR)$(LIBFT_A) $(MLX_DIR)$(MLX_A) -framework OpenGL -framework AppKit -o $@ 
	@echo "> FdF Done!\n"
	
# TODO: separate libft and mlx
build_lib: $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT_DIR) $(INC_DIR)$(INC) Makefile
	@mkdir -p $(@D)
	@echo "$(_GREEN)compiling: $<$(_END)"
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAG) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

# clean commands
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)
	@echo "remove $(LIBFT_DIR)$(LIBFT_A)"
	@rm -rf "$(LIBFT_DIR)$(LIBFT_A)"

re: fclean all

.PHONY: all clean fclean re build_lib
