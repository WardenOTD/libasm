SRC			= ft_strlen.s ft_strcpy.s ft_strcmp.s\
				ft_write.s ft_read.s\

OBJ			= $(SRC:.s=.o)

NAME		= libasm.a

EXE			= exec

ASM			= nasm
ASM_FLAGS	= -f elf64 -g
FLAGS		= -Wall -Wextra -Werror -L. -lasm

all: $(NAME)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

link: $(NAME)
	gcc $(FLAGS) main.c $(NAME) -o $(EXE)
	@ ./exec

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(EXE)

re: fclean $(NAME)

.PHONY: clean fclean re