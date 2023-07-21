
CC=g++

CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wnull-dereference -Wsign-conversion -g3 -O0

SRCS=$(wildcard *.cc)
OBJS=$(patsubst %.cc,%.o,$(SRCS))

PROGRAM=CG

all: $(PROGRAM)

$(OBJS): %.o : %.cc
	$(CC) -c src/base/vector/ClassVector.h
	$(CC) $(CFLAGS) $<


$(PROGRAM) : $(OBJS)
	$(CC) main.cc $(CFLAGS)