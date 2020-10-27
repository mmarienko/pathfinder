SRC = src/*.c
INC = inc/*.h
OBJ = obj/*.o

LIB = libmx.a
FOLDER = obj

CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
RM = rm -rf

all: LIBMX

LIBMX:
	mkdir $(FOLDER)
	$(CLANG) -c $(SRC) -I $(INC)
	mv *.o $(FOLDER)
	ar -crs $(LIB) $(OBJ)
	ranlib $(LIB)

uninstall:
	$(RM) $(FOLDER)
	$(RM) $(LIB)

clean:
	$(RM) $(FOLDER)

reinstall:
	make uninstall
	make