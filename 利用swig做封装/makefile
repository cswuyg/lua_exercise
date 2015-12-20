OBJ=main.o my_module.o my_module_wrap.o
CC=g++
CFLAGS=-DSWIGRUNTIME_DEBUG
ROOTDIR=./../
LUADIR=/home/users/cswuyg/install/lua/
LIBS=-llua -ldl

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ) -L$(LUADIR)lib $(LIBS) -L/usr/local/bin -L/usr/lib

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -I$(LUADIR)include

my_module.o: my_module.cpp
	$(CC) $(CFLAGS) -c my_module.cpp -I$(LUADIR)include

my_module_wrap.o: my_module_wrap.cxx
	$(CC) $(CFLAGS) -c my_module_wrap.cxx -I$(LUADIR)include

clean:
	rm *.o main
