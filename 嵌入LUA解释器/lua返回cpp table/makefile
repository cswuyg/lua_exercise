OBJ=test.o
CC=g++
CFLAGS=-Wl,-E
ROOTDIR=./../
LUADIR=/usr/local/app/theodorewu/src/test_lua/lua_install/
LIBS=-lluajit-5.1 -ldl

test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ) -L$(LUADIR)lib $(LIBS)

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -I$(LUADIR)include
clean:
	rm test.o test
