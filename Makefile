###############################################################################
###############################################################################
#*****************************************************************************#
#********************** Makefile for cub3D project  **************************#
#*****************************************************************************#
###############################################################################
###############################################################################

NAME			= cub3D
CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra -g3 -Imlx
BONUS  			= 

###############################################################################
###############################################################################

LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a

###############################################################################
###############################################################################

PLATFORM		=	$(shell uname -s)

ifeq ($(PLATFORM), Darwin)
	OS			=	macos
else ifeq ($(PLATFORM), Linux)
	OS			=	linux
endif

###############################################################################
###############################################################################

# ifeq ($(PLATFORM), Darwin)
# 	MINILIBX_PATH 	=	./mlx-opengl
# 	MINIFLAGS		=	-framework OpenGL -framework Appkit -lz
# else
	MINILIBX_PATH 	=	./mlx-linux
	MINIFLAGS		=	-L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm -lbsd
# endif
MINILIBX			= $(MINILIBX_PATH)/libmlx.a

###############################################################################
###############################################################################

MAINFILES 		= main.c
PARSINGFILES 	= utils.c \
				get_raw_input.c \
				check_input_order.c \
				check_closed.c \
				parse_colors.c \
			    tab_manip.c \
				get_texture_paths.c \
				free.c \
				parse_map.c
RUNFILES 		= draw.c \
				init_player.c \
				hooks.c \
				minimap_utils.c \
				inits.c \
				utils.c \
				ray_casting.c \
				on_keypress.c \
				minimap.c \
				start_game.c
MVTFILES	 	= mouvements.c \
				mouse.c
ANIMATIONFILES	= hud_utils.c \
				hud.c 

###############################################################################
###############################################################################

INCS = ./include
PATHS	= $(addprefix main/, $(MAINFILES))\
		$(addprefix run/, $(RUNFILES))\
		$(addprefix parsing/, $(PARSINGFILES))\
		$(addprefix mouvements/, $(MVTFILES))\
		$(addprefix animations/, $(ANIMATIONFILES))
SRCS = $(addprefix $(SRCDIRS)/, $(PATHS))
SRCDIRS = srcs
OBJDIRS = objs
OBJS = $(addprefix $(OBJDIRS)/, $(patsubst %.c, %.o, $(PATHS)))

###############################################################################
###############################################################################

GREEN			=	\033[0;32m
END				=	\033[0m

###############################################################################
###############################################################################

all: $(NAME)

$(NAME): 	$(MINILIBX) $(LIBFT) $(OBJDIRS) $(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINIFLAGS) -I$(INCS) -L$(LIBFT_DIR) -lft
			@echo "${GREEN}> ${NAME} was successfuly compiled 🎉${END}"

$(OBJDIRS):
	@mkdir -p $(OBJDIRS)
	@mkdir -p $(addprefix $(OBJDIRS)/, main)
	@mkdir -p $(addprefix $(OBJDIRS)/, run)
	@mkdir -p $(addprefix $(OBJDIRS)/, parsing)
	@mkdir -p $(addprefix $(OBJDIRS)/, mouvements)
	@mkdir -p $(addprefix $(OBJDIRS)/, animations)

$(MINILIBX):
			@make -C $(MINILIBX_PATH)
			@echo "${GREEN}> ${MINILIBX} was successfuly compiled 🎉${END}"

$(LIBFT):
			@make -C $(LIBFT_DIR)
			@echo "${GREEN}> ${LIBFT} was successfuly compiled 🎉${END}"

$(OBJDIRS)/%.o: $(SRCDIRS)/%.c
			@$(CC) $(CFLAGS) $(BONUS) -I$(INCS) -c $< -o $@

bonus:
			@make BONUS="-D BONUS=1" $(NAME)

###############################################################################
###############################################################################

clean:
			@make -C $(LIBFT_DIR) clean
			@rm -rf $(OBJDIRS)
			@echo "${GREEN}> Objects deleted${END}"

fclean : clean
			@rm -f ${NAME}
			@echo "${GREEN}> Cleaning of ${NAME} has been done${END}"

re: fclean all

norm:
	norminette $(SRCS) $(INCS)

.PHONY: all clean fclean re bonus
