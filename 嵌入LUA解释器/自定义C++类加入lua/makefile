OBJ=lua_wrapper.o main.o
CC=g++
CFLAGS=
ROOTDIR=./../
LUADIR=/home/users/cswuyg/install/lua/
LIBS=-llua -ldl -lmydate

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ) -L$(LUADIR)lib $(LIBS) -L./mydate/ -L/usr/local/bin -L/usr/lib

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -I$(LUADIR)include

lua_wrapper.o: lua_wrapper.cpp
	$(CC) $(CFLAGS) -c lua_wrapper.cpp -I$(LUADIR)include

clean:
	rm *.o main
