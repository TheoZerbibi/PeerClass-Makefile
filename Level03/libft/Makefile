# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:36:23 by thzeribi          #+#    #+#              #
#    Updated: 2024/02/23 10:44:57 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   CONFIG                                     #
################################################################################

ifndef VERBOSE
	MAKEFLAGS += --no-print-directory --silent
endif

NAME			:= libft.a
PROJECT_NAME	:= LibFt


################################################################################
#                                  SOURCES                                     #
################################################################################

SOURCES_FOLDER	:= ./srcs/
INCLUDES_FOLDER	:= ./includes/
OBJECTS_FOLDER	:= ./objs/

SOURCES_STRING_FOLDER	:= string/
SOURCES_NUMBER_FOLDER	:= number/
SOURCES_MEMORY_FOLDER	:= memory/
SOURCES_LIST_FOLDER		:= list/
SOURCES_CHAR_FOLDER		:= char/
SOURCES_OUTPUT_FOLDER	:= output/
SOURCES_FILE_FOLDER		:= file/
SOURCES_DEBUG_FOLDER	:= debug/
SOURCES_GNL_FOLDER		:= gnl/
SOURCES_VECTOR_FOLDER	:= vector/
SOURCES_GARBAGE_FOLDER	:= garbage/

SOURCES_STRING := \
	ft_charcat.c ft_strcat.c ft_contain.c ft_strrev.c \
	ft_strtrim.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strrchr.c ft_itoa_base.c ft_itoa.c \
	ft_split.c ft_strchr.c ft_strcpy.c ft_strndup.c ft_strdup.c \
	ft_strnew.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strcmp.c ft_strnstr.c \

SOURCES_NUMBER := \
	ft_atoi.c ft_swap.c ft_nbrlen.c ft_check_int_limit.c \

SOURCES_MEMORY := \
	ft_calloc.c ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_memdel.c ft_atol.c \
	ft_substr.c ft_init_tab.c \

SOURCES_LIST := \
	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \

SOURCES_CHAR := \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_isspace.c ft_tolower.c ft_toupper.c \

SOURCES_OUTPUT := \
	ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putnbrmax_fd.c ft_putstr.c ft_putstr_fd.c \
	ft_putlnbr_base.c \

SOURCES_FILE := \
	ft_file_ext.c ft_display_file.c \

SOURCES_DEBUG := \
	ft_stack_trace.c \

SOURCES_GNL := \
	get_next_line.c \

SOURCES_VECTOR := \
	vector_utils.c vector.c \

SOURCES_GARBAGE := \
	gc_clear.c gc_malloc.c gc.c \

SOURCES_STRING := $(addprefix $(SOURCES_STRING_FOLDER),$(SOURCES_STRING))
SOURCES_NUMBER := $(addprefix $(SOURCES_NUMBER_FOLDER),$(SOURCES_NUMBER))
SOURCES_MEMORY := $(addprefix $(SOURCES_MEMORY_FOLDER),$(SOURCES_MEMORY))
SOURCES_LIST := $(addprefix $(SOURCES_LIST_FOLDER),$(SOURCES_LIST))
SOURCES_CHAR := $(addprefix $(SOURCES_CHAR_FOLDER),$(SOURCES_CHAR))
SOURCES_OUTPUT := $(addprefix $(SOURCES_OUTPUT_FOLDER),$(SOURCES_OUTPUT))
SOURCES_FILE := $(addprefix $(SOURCES_FILE_FOLDER),$(SOURCES_FILE))
SOURCES_DEBUG := $(addprefix $(SOURCES_DEBUG_FOLDER),$(SOURCES_DEBUG))
SOURCES_GNL := $(addprefix $(SOURCES_GNL_FOLDER),$(SOURCES_GNL))
SOURCES_VECTOR := $(addprefix $(SOURCES_VECTOR_FOLDER),$(SOURCES_VECTOR))
SOURCES_GARBAGE := $(addprefix $(SOURCES_GARBAGE_FOLDER),$(SOURCES_GARBAGE))

SOURCES := \

################################################################################
#                                  FLAGS                                       #
################################################################################

CFLAGS = -Wall -Wextra -Werror -MMD
CC = gcc

INCLUDES = -I$(INCLUDES_FOLDER)


-include .CONFIG
STRING	?= 0
NUMBER	?= 0
MEMORY	?= 0
LIST	?= 0
CHAR	?= 0
OUTPUT	?= 0
FILE	?= 0
DEBUG	?= 0
GNL		?= 0
VECTOR	?= 0
GARBAGE	?= 0

CONFIG_VARS := STRING NUMBER MEMORY LIST CHAR OUTPUT FILE DEBUG GNL VECTOR GARBAGE

################################################################################
#                                  LOGICS                                      #
################################################################################

define CONFIG_RULE
	if [ -e .CONFIG ]; then \
		cp .CONFIG .CONFIG.tmp; \
		nano .CONFIG; \
		if [ "$$(diff .CONFIG .CONFIG.tmp)" ]; then \
			make re; \
		fi; \
		rm -f .CONFIG.tmp; \
	else \
		for VAR in $(CONFIG_VARS); do \
			echo "$$VAR = 0" >> .CONFIG; \
		done; \
		nano .CONFIG; \
		make; \
	fi
endef

ifneq (,$(wildcard ./.CONFIG))
	include .CONFIG
else ifeq ($(filter $(MAKECMDGOALS), clean fclean config),)
    $(shell for VAR in $(CONFIG_VARS); do \
			echo "$$VAR = 0" >> .CONFIG; \
		done;)
endif

CONFIG_VARS := STRING NUMBER MEMORY LIST CHAR OUTPUT FILE DEBUG GNL VECTOR GARBAGE

define ADD_SOURCE
	ifneq ($($(1)), 0)
		SOURCES += $($(2))
	endif
endef

$(foreach VAR,$(CONFIG_VARS),$(eval $(call ADD_SOURCE,$(VAR),SOURCES_$(VAR))))


################################################################################
#                                  OBJETS                                      #
################################################################################

OBJECTS		:=	$(SOURCES:.c=.o)
OBJECTS		:=	$(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES		:=	$(addprefix $(SOURCES_FOLDER),$(SOURCES))
DEPS		:=	$(OBJECTS:.o=.d)

################################################################################
#                                 COLORS                                       #
################################################################################

NO_COLOR =		\033[38;5;15m
OK_COLOR =		\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR =	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR =	\033[38;5;140m

################################################################################
#                                 RULES                                        #
################################################################################

all: $(NAME)

$(NAME): $(OBJECTS)
	printf "\t\t$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	printf "\t\t$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

-include $(DEPS)
$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c .CONFIG
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	printf "%-50s \r"
	printf "\t\t\t$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

config: .CONFIG
	$(CONFIG_RULE)

.CONFIG:
	nano .CONFIG

clean:
	rm -f $(OBJECTS)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJECTS_FOLDER)

norm:
	printf "\n$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Norm check$(NO_COLOR).\n\n"
	norminette ${SOURCES_FOLDER} ${INCLUDES_FOLDER} $(LIBFT_FOLDER) | grep 'Error' ; true

re: fclean all

.PHONY: all re clean fclean norm config makelib
