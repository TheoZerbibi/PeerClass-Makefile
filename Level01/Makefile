CC				:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I./

all: peerclass1

peerclass1: main.o test.o
	# LINKAGE
	$(CC) -o peerclass1 main.o test.o $(CFLAGS)
	@echo "$@ has been created"

main.o: main.c
	$(CC) $(CPPFLAGS) -c main.c -o main.o $(CFLAGS)
	@echo "$@ has been compiled" 

test.o: test.c
	@echo
	$(CC) $(CPPFLAGS) -c test.c -o test.o $(CFLAGS)
	@echo "$@ has been compiled\n"

fclean:
	rm -f *.o peerclass1

.PHONY: fclean all
# = := ?= +=
