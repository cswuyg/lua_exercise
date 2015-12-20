OBJ=my_date.o lua_my_date.o
CC=g++
CFLAGS=
LUADIR=/home/users/wuyinguang/install/lua/

libmydate.a: $(OBJ)
	ar $(CFLAGS) cr libmydate.a $(OBJ)

my_date.o: my_date.h my_date.cpp
	$(CC) $(CFLAGS) -c my_date.cpp

lua_my_date.o: lua_my_date.h lua_my_date.cpp
	$(CC) $(CFLAGS) -c lua_my_date.cpp -I$(LUADIR)include

clean:
	rm *.o *.a
