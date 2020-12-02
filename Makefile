SRC = src/*.c
INC = inc/*.h
OBJ = obj/*.o
FOLDER = obj
CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
RM = rm -rf

LIB = libmx.a
BINARY = pathfinder

all: PATHFINDER

PATHFINDER: libmx.a
	@mkdir $(FOLDER)
	@$(CLANG) -c $(SRC) -I $(INC)
	@mv *.o $(FOLDER)
	@clang $(OBJ) libmx/$(LIB) -o $(BINARY)

libmx.a: 
	@make -C libmx

uninstall:
	@make uninstall -C libmx
	@$(RM) $(FOLDER)
	@$(RM) $(BINARY)

clean:
	@make clean -C libmx
	@$(RM) $(FOLDER)

reinstall:
	@make reinstall -C libmx
	@make uninstall
	@make