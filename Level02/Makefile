CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS    := -I./include
LDFLAGS     :=  
LDLIBS      :=  

NAME        := peerclass2

SRC_DIR     := ./src/
OBJ_DIR     := ./obj/
INC_DIR     := ./include/

SOURCES     := main.c test.c
SOURCES     := $(addprefix $(SRC_DIR),$(SOURCES))
OBJECTS     := $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS        := $(OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;33m-----------------------------------"
	@echo "$^ | $@"
	@echo "-----------------------------------\033[0m"
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@echo "$@ has been created"

-include $(DEPS)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "\n\033[0;33m-------------------------------------------------------------------------"
	@echo "$^ | $< | $@ | $* | $(@F)"
	@echo "-------------------------------------------------------------------------\033[0m"
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "$(@F) has been compiled"

clean:
	rm -f $(OBJECTS) $(DEPS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
