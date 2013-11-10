CC = g++
CFLAGS = -Wall
PROG = maps


SRCS = main.cpp imageloader.cpp glm.cpp
LIBS = -lglut -lGL -lGLU -lm

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
