# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:36:23 by thzeribi          #+#    #+#              #
#    Updated: 2022/07/26 05:43:39 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROJECT_NAME = LibFt

SOURCES_FOLDER = ./srcs/
INCLUDES_FOLDER = ./includes/
OBJECTS_FOLDER = ./objs/

INCLUDE_SOURCES = \
		libft.h \
		garbage.h \
		vector.h \

SOURCES = \
		libft/ft_atoi.c \
		libft/ft_atoi_base.c \
		libft/ft_atol.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_isspace.c \
		libft/ft_itoa.c \
		libft/ft_itoa_base.c \
		libft/ft_check_int_limit.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstmap_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_nbrlen.c \
		libft/ft_putchar.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strcpy.c \
		libft/ft_strndup.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strnew.c	\
		libft/ft_strmapi.c \
		libft/ft_strncat.c \
		libft/ft_strncmp.c \
		libft/ft_strcmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strrev.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_init_tab.c \
		libft/ft_file_ext.c \
		libft/ft_memdel.c \
		libft/ft_display_file.c \
		libft/ft_putnbrmax_fd.c \
		libft/ft_putlnbr_base.c \
		libft/get_next_line.c \
		libft/ft_stack_trace.c \
		libft/ft_strcat.c \
		libft/ft_contain.c \
		libft/ft_swap.c \
		libft/ft_charcat.c \
		\
		garbage/gc.c \
		garbage/gc_malloc.c \
		garbage/gc_clear.c \
		\
		vector/vector.c \
		vector/vector_utils.c \
		\


OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))
INCLUDE_FILE := $(addprefix $(INCLUDES_FOLDER),$(INCLUDE_SOURCES))

FLAGS = -Wall -Wextra -Werror -g3
CC = gcc

NO_COLOR =		\033[38;5;15m
OK_COLOR =		\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR =	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR =	\033[38;5;140m

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\t\t$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\t\t$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@mkdir -p $(OBJECTS_FOLDER)/libft
	@mkdir -p $(OBJECTS_FOLDER)/garbage
	@mkdir -p $(OBJECTS_FOLDER)/vector
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "\t\t\t$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_FOLDER)
	printf "\t\t$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

re: fclean all

norm:
	@printf "\n$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Norm check$(NO_COLOR).\n\n"
	@norminette ${SOURCES_FOLDER} ${INCLUDES_FOLDER} | grep 'Error' ; true

.PHONY: all re clean fclean norm
