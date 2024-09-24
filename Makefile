FLAGS = -g

SRCS = *.c
OBJS = $(SRCS:.c=.o)
LIBS = -I./headers/

.PHONY: clean

$(OBJS): $(SRCS)
	gcc -c $(FLAGS) $(SRCS) 

clean:
	rm *.o