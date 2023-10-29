# Makefile for Login.c

CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses

# Executable name
TARGET = login

# Source files
SRCS = Login.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = Login.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)
