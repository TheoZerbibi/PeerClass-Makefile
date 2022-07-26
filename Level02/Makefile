# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 12:13:48 by thzeribi          #+#    #+#              #
#    Updated: 2022/07/26 07:39:08 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

NAME				=	peerclass2
PROJECT_NAME		=	PeerClass

################################################################################
#                                 SOURCES                                      #
################################################################################
SOURCES_FOLDER		=	./srcs/
INCLUDES_FOLDER		=	./privates/
OBJECTS_FOLDER		=	./objs/
LIBFT_FOLDER		=	./libft/

SOURCES := \
		main.c \


LIBFT		= -L $(LIBFT_FOLDER) -lft

################################################################################
#                                  OBJETS                                      #
################################################################################

OBJECTS		 =	$(SOURCES:.c=.o)
OBJECTS		:=	$(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES		:=	$(addprefix $(SOURCES_FOLDER),$(SOURCES))
DEPS		 =	$(OBJECTS:.o=.d)

################################################################################
#                                  FLAGS                                       #
################################################################################

FSANITIZE		=	-g3 -fsanitize=address
FLAGS			=	-Wall -Wextra -Werror -MMD
CC				=	cc

INCLUDES		= -I$(INCLUDES_FOLDER) -I$(LIBFT_FOLDER)includes

################################################################################
#                                 LOGIC                                       #
################################################################################

NO_COLOR 		=	\033[38;5;15m
OK_COLOR		=	\033[38;5;2m
ERROR_COLOR		=	\033[38;5;1m
WARN_COLOR		=	\033[38;5;3m
SILENT_COLOR	=	\033[38;5;245m
INFO_COLOR		=	\033[38;5;140m
OBJ_COLOR		=	\033[0;36m

################################################################################
#                                 RULES                                        #
################################################################################

all: $(NAME)

$(NAME): $(OBJECTS)
	printf "\t\t$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	$(MAKE) -C $(LIBFT_FOLDER)
	printf "\t\t$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"
	printf "\n\t\t$(NO_COLOR)-------- $(INFO_COLOR) Start Compilation for ${PROJECT_NAME} $(NO_COLOR)--------\n"	
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)
	printf "%-50s \r"
	printf "\t\t$(INFO_COLOR)$(NAME)$(NO_COLOR) successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

force: $(OBJECTS)
	printf "\t\t\t$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	$(MAKE) -C $(LIBFT_FOLDER)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)
	printf "%-50s \r"
	printf "\t\t\t$(INFO_COLOR)$(NAME)$(NO_COLOR) successfully force compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

-include $(DEPS)
$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	printf "%-50s \r"
	printf "\t\t\t$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	rm -f $(NAME)
	rm -rf $(OBJECTS_FOLDER)
	printf "\t\t$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

doclean: all clean

re: fclean all

.PHONY: all re clean fclean force doclean

-include ../Templates/coffee.mk
-include ../Templates/norme.mk