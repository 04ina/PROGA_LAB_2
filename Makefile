FLAGS = -g

SRCS = *.c
OBJS = $(SRCS:.c=.o)
LIBS = -I./headers/

.PHONY: all clean

$(OBJS): $(SRCS)
	gcc -c $(FLAGS) $(SRCS) 

all:


	gcc -o program $(OBJS) 

clean:
	rm -f program
	rm -f *.o
