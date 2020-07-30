CC=nasm
NAME=libasm.a
TESTER=main
SRC= \
		ft_strlen.s \
		ft_strcpy.s# \
#		ft_strcmp.s \
#		ft_write.s	\
#		ft_read.s	\
#		ft_strdup.s
OBJ=$(SRC:.s=.o)
SRC_BONUS=
OBJ_BONUS=$(SRC_BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.s
	$(CC) -f elf64 -o $@ $<

$(TESTER): $(NAME) $(TESTER).c
	gcc -o $(TESTER) $(TESTER).c $(NAME)

test: $(TESTER)
	./$(TESTER)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean:	clean	
		rm -rf $(NAME) $(TESTER)

re: fclean all
