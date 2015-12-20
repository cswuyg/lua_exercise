OBJ=test.o
CC=g++
CFLAGS=
ROOTDIR=./../
LUADIR=/home/users/cswuyg/install/lua/
LIBS=-llua -ldl

test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ) -L$(LUADIR)lib $(LIBS)

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -I$(LUADIR)include
