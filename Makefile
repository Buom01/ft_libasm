ASM=nasm
NAME=libasm.a
TESTER=main
CC=clang
CFLAGS=-Wall -Wextra -Werror
SRC= \
		ft_strlen.s	\
		ft_strcpy.s	\
		ft_strcmp.s	\
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s
OBJ=$(SRC:.s=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.s
	$(ASM) -f elf64 -o $@ $<

$(TESTER): $(NAME) $(TESTER).c
	$(CC) -o $(TESTER) $(TESTER).c $(CFLAGS) $(NAME)

test: $(TESTER)
	./$(TESTER)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean:	clean	
		rm -rf $(NAME) $(TESTER)

re: fclean all
