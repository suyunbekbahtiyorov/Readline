CC=gcc
CFLAGS= -g -Wall -Wextra -Werror
COURCES =my_readline.c 
TARGET = my_readline 


$(TARGET):$(COURCES)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all