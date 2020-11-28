SRC = src/*.c
INC = inc/*.h
OBJ = obj/*.o
LIB = libmx.a
FOLDER = obj
RM_FLAG = -rf

all: LIBMX

LIBMX:
	@echo "make: compile libmx"
	@mkdir $(FOLDER)
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $(SRC) -I $(INC)
	@mv *.o $(FOLDER)
	@ar -crs $(LIB) $(OBJ)
	@ranlib $(LIB)

uninstall:
	@echo "make: remove libmx"
	@rm $(RM_FLAG) $(FOLDER)
	@rm $(RM_FLAG) $(LIB)

clean:
	@echo "make: clean libmx"
	@rm $(RM_FLAG) $(FOLDER)

reinstall:
	@make uninstall
	@make