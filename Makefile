NAME=libasm.a
NAME_BONUS=libasm_bonus.a
ASM=nasm
ASMFLAGS=-f elf64 -Wall -g -F dwarf
TESTER=main
TESTER_BONUS=main_bonus
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
SRC_BONUS= \
		ft_atoi_base_bonus.s		\
		ft_list_push_front_bonus.s	\
		ft_list_size_bonus.s		\
		ft_list_remove_if_bonus.s	
#		ft_list_sort_bonus.s
OBJ_BONUS=$(SRC_BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME_BONUS) $(OBJ) $(OBJ_BONUS)
	cp $(NAME_BONUS) $(NAME)

bonus: $(NAME_BONUS)

%.o: %.s
	$(ASM) -o $@ $< $(ASMFLAGS)

$(TESTER): $(NAME) $(TESTER).c
	$(CC) -o $(TESTER) $(TESTER).c $(CFLAGS) $(NAME)

test: $(TESTER)
	./$(TESTER)

$(TESTER_BONUS): $(NAME_BONUS) $(TESTER_BONUS).c
	$(CC) -o $(TESTER_BONUS) $(TESTER_BONUS).c $(CFLAGS) $(NAME_BONUS)

test_bonus: $(TESTER_BONUS)
	./$(TESTER_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean:	clean	
		rm -rf $(NAME) $(NAME_BONUS) $(TESTER) $(TESTER_BONUS)

re: fclean all

re_bonus: fclean bonus
