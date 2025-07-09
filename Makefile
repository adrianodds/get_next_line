NAME = get_next_line.a

SOURCES = get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all