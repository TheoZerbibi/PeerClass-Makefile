# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    header.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 01:52:22 by thzeribi          #+#    #+#              #
#    Updated: 2022/07/26 07:38:51 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT_SPACE = 63

RULE = $(filter all re clean fclean doclean norm header test fsanitize,$(MAKECMDGOALS))

AUTHOR	= thzeribi
DATE	= $(shell date +%F)

define print_header
	printf "%b" "$(INFO_COLOR)";
	echo "=============================================================================================="
	echo "|| $(OK_COLOR) _______  _______  _        _______  $(OBJ_COLOR)    _______ _________ _______  _______  _$(INFO_COLOR)           ||";
	echo "|| $(OK_COLOR)(       )(  ___  )| \    /\(  ____ \ $(OBJ_COLOR)   (  ___  )\__   __/(  ____ )(  ___  )( (    /|$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)| () () || (   ) ||  \  / /| (    \/ $(OBJ_COLOR)   | (   ) |   ) (   | (    )|| (   ) ||  \  ( |$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)| || || || (___) ||  (_/ / | (__  ___$(OBJ_COLOR)__ | (___) |   | |   | (____)|| |   | ||   \ | |$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)| |(_)| ||  ___  ||   _ (  |  __)(___$(OBJ_COLOR)__)|  ___  |   | |   |     __)| |   | || (\ \) |$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)| |   | || (   ) ||  ( \ \ | (       $(OBJ_COLOR)   | (   ) |   | |   | (\ (   | |   | || | \   |$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)| )   ( || )   ( ||  /  \ \| (____/\ $(OBJ_COLOR)   | )   ( |   | |   | ) \ \__| (___) || )  \  |$(INFO_COLOR)    ||";
	echo "|| $(OK_COLOR)|/     \||/     \||_/    \/(_______/ $(OBJ_COLOR)   |/     \|   )_(   |/   \__/(_______)|/    )_).V1$(INFO_COLOR) ||";
	echo "||                                                                                          ||";
	printf "\033[m$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tName:	$(OBJ_COLOR)   $(NAME)\033[m"
	$(call print_spaces,$(NAME))
	printf "$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tAuthor:	$(OBJ_COLOR)   $(AUTHOR)\033[m"
	$(call print_spaces,$(AUTHOR))
	printf "$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tDate: 	$(OBJ_COLOR)   $(DATE)\033[m"
	$(call print_spaces,$(DATE))
	printf "$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tCC: 	$(OBJ_COLOR)   $(CC)\033[m"
	$(call print_spaces,$(CC))
	printf "$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tFlags: 	$(OBJ_COLOR)   $(FLAGS)\033[m"
	$(call print_spaces,${FLAGS})
	printf "$(INFO_COLOR)|| $(OK_COLOR)\t\t\t\tRule: 	$(OBJ_COLOR)   $(RULE)\033[m"
	$(call print_spaces,$(RULE))
	echo "$(INFO_COLOR)||                                                                                          ||";
	echo "=============================================================================================="
endef

define print_spaces
	ARG="$(1)"; \
	LEN=$${#ARG}; \
	SIZE=$$(( $(DEFAULT_SPACE) - $${LEN} )); \
	printf "%$${SIZE}b" "$(INFO_COLOR)||\n";
endef

header:
	clear
	$(call print_header)