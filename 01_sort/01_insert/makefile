CC := g++

CFLAGS := -std=c++14 -Wall -Werror

OBJS := sort.o

ifeq ($(mode), debug)
    CFLAGS += -g3 -ggdb
endif

ifeq ($(mode), release)
    CFLAGS += -DNDEBUG -g0
endif

app.exe: $(OBJS) main.o
	$(CC) $^ -o app.exe
	
test.exe: $(OBJ2) test.o
	$(CC) $^ -o app.exe
	
%.o: %.c *.hpp
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) *.o *.exe