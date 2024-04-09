NAME = minihell

src = main.c

obj = ${src:.c=.o}

#%.o:%.c
#	cc $(src) -c $< -o $@


NAME: all

all: $(obj)
	cc $(src) -lreadline -L ./readline/lib -I ./readline/include

clean:
	rm -f $(obj)

fclean: clean

re: clean all

.PHONY: all clean fclean re
