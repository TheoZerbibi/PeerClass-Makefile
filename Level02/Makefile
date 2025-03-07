CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
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
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)
	@echo "$@ has been created"

-include $(DEPS)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$^ | $< | $@"
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$@ has been compiled\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	@echo

clean:
	rm -f $(OBJECTS) $(DEPS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
