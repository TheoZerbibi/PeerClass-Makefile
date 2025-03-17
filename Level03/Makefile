################################################################################
# Configuration
################################################################################

NAME          := peerclass3
CC            := gcc
CFLAGS        := -Wall -Wextra -Werror -MMD -MP

SRC_DIR       := ./src
OBJ_DIR       := ./obj
LIBFT_FOLDER  := ./libft
MLX_FOLDER    := ./minilibx-linux

LDFLAGS       := -L$(LIBFT_FOLDER) -L$(MLX_FOLDER)
LDLIBS        := -lpthread -lm -lmlx -lXext -lX11 -lft
CPPFLAGS      := -I./include -I$(LIBFT_FOLDER)/includes -I$(MLX_FOLDER)

################################################################################
# Sources / Objects
################################################################################

SOURCES := \
  main.c \
  mlx/init/mlx_init.c \
  mlx/init/hook_init.c \
  mlx/end/mlx_end.c \
  mlx/event/key_event.c \
  mlx/event/mouse_event.c \
  utils/exit_case.c

SOURCES := $(addprefix $(SRC_DIR)/,$(SOURCES))
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
DEPS    := $(OBJECTS:.o=.d)

################################################################################
# Main rules
################################################################################

.PHONY: all clean fclean re setup_mlx makelib

all: setup_mlx makelib $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;33m-----------------------------------"
	@echo "$^ → $@"
	@echo "-----------------------------------\033[0m"
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@echo "$@ has been created"

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\n\033[0;33m-------------------------------------------------------------------------"
	@echo "$^ | $< | $@ | $* | $(@F)"
	@echo "-------------------------------------------------------------------------\033[0m"
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "$(@F) has been compiled"

################################################################################
# Cleaning
################################################################################

clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(MAKE) -C $(MLX_FOLDER) clean --quiet --jobs
	@rm -f $(OBJECTS) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	@rm -rf $(MLX_FOLDER)
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

################################################################################
# Build external lib
################################################################################

$(MLX_FOLDER)/libmlx.a:
	$(MAKE) -C $(MLX_FOLDER) all --quiet

makelib: $(MLX_FOLDER)/libmlx.a
	$(MAKE) -C $(LIBFT_FOLDER)

setup_mlx:
	@if [ ! -d "$(MLX_FOLDER)" ]; then \
		echo "MLX_FOLDER not found. Setting up MLX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_FOLDER); \
		$(MAKE) -C $(MLX_FOLDER); \
	else \
		echo "MLX_FOLDER already exists. Skipping setup."; \
	fi
