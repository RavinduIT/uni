CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bst
SRCS = bst.c
OBJS = bst.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
