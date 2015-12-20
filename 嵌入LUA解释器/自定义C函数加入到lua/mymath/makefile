OBJ=my_math.o lua_my_math.o
CC=g++
CFLAGS=
LUADIR=/home/users/wuyinguang/install/lua/

libmymath.a: $(OBJ)
	ar $(CFLAGS) cr libmymath.a $(OBJ)

my_math.o: my_math.h my_math.cpp
	$(CC) $(CFLAGS) -c my_math.cpp

lua_my_math.o: lua_my_math.h lua_my_math.cpp
	$(CC) $(CFLAGS) -c lua_my_math.cpp -I$(LUADIR)include
