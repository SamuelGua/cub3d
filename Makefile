COLOR_RESET = \033[0m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_YELLOW = \033[93m
COLOR_BOLD = \033[1m
MAKEFLAGS += --no-print-directory

NAME			:= cub3D

SRC_DIR			:= src
OBJ_DIR			:= obj
SRCS			= $(LIBFT_PATH) $(EXEC_PATH) $(RAYCAST_PATH) $(MOVE_PATH) $(PARSING_PATH)

LIBFT_PATH		= $(LIBFT:%=src/libft/%)
LIBFT			= ft_atoi.c ft_isprint.c ft_lstmap_bonus.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c\
					ft_bzero.c ft_itoa.c ft_lstnew_bonus.c ft_putendl_fd.c ft_strlcat.c ft_substr.c\
					ft_calloc.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c\
					ft_free.c ft_lstadd_front_bonus.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c\
					ft_isalnum.c ft_lstclear_bonus.c ft_memcmp.c ft_split.c ft_strmapi.c get_next_line.c\
					ft_isalpha.c ft_lstdelone_bonus.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c\
					ft_lstiter_bonus.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_free_strjoin.c\
					ft_isdigit.c ft_lstlast_bonus.c ft_memset.c ft_striteri.c ft_strrchr.c ft_atoll.c get_next_line_utils.c\

EXEC_PATH			= $(EXEC:%=src/exec/%)
EXEC				= main.c init_data.c free_elements.c

MOVE_PATH			= $(MOVE:%=src/move/%)
MOVE				= move.c rotate.c

RAYCAST_PATH		= $(RAYCAST:%=src/raycast/%)
RAYCAST				= cast_wall.c cast_floor_ciel.c cast_utils_1.c cast_utils_2.c


PARSING_PATH		= $(PARSING:%=src/parsing/%)
PARSING				= checking.c get_data.c utils.c check_map.c get_sens.c utils2.c utils3.c

INCLUDE			= include/libft.h include/cub3d.h

OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS			:= -Wall -Wextra -Werror
CFLAGS          += -g3
CCFLAGS			:= -I include


RM				:= rm -rf
DIR_DUP			= mkdir -p $(@D)

FILE_TO_CHECK	:= minilibx
FILE_EXISTS		:= $(shell [ -e $(FILE_TO_CHECK) ] && echo 1 || echo 0)

all: $(NAME)

CHECK-FILE:
ifeq ($(FILE_EXISTS), 0)
	@echo "Le dossier $(FILE_TO_CHECK) n'existe pas."
	@git clone https://github.com/42Paris/minilibx-linux.git
	mv minilibx-linux minilibx
	@echo "MLX is download from https://github.com/42Paris/minilibx-linux.git"
endif

$(NAME): CHECK-FILE $(OBJS)
		@make -C minilibx
		@$(CC) $(OBJS) minilibx/libmlx_Linux.a -L mlx -lXext -lX11 -lm -o $(NAME)
		@echo "$(COLOR_GREEN)$(COLOR_BOLD)Compilation finie ✅$(COLOR_RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
		@$(DIR_DUP)
		$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C minilibx/ clean

fclean: clean
	@$(RM) $(OBJ_DIR) $(NAME)
	@$(RM) minilibx
	@echo "$(COLOR_RED)$(COLOR_BOLD)All files are deleted 🗑️$(COLOR_RESET)"


re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
