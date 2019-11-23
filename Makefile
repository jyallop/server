vpath %.c src
vpath %.h include

COMPILER_OPTS = -Iinclude -g

_OBJS = linked_list.o server.o
OBJS = $(patsubst %, build/%, $(_OBJS))

TARGET = server

$(TARGET):  $(_OBJS)
	gcc main.c -o $@ $(OBJS) $(COMPILER_OPTS)

%.o: %.c
	gcc -c $< -o build/$@ $(COMPILER_OPTS)

clean:
	rm $(TARGET) $(OBJS)
