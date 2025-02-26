SRC			= $(addprefix mandatory/,\
				ft_strlen.s ft_strcpy.s ft_strcmp.s\
				ft_write.s ft_read.s ft_strdup.s\
				)

BSRC		= $(addprefix bonus/,\
				$(addsuffix _bonus.s,\
				ft_atoi_base ft_list_push_front ft_list_size\
				))

OBJ			= $(SRC:.s=.o)
BOBJ		= $(BSRC:.s=.o)

NAME		= libasm.a
BNAME		= libasm_bonus.a

EXE			= exec
BEXE		= bexec

ASM			= nasm
ASM_FLAGS	= -f elf64 -g
FLAGS		= -Wall -Wextra -Werror -L. -lasm
BFLAGS		= -Wall -Wextra -Werror -L. -lasm_bonus

all: $(NAME)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BOBJ)
	ar rcs $(BNAME) $(BOBJ)

link: $(NAME)
	gcc $(FLAGS) main.c $(NAME) -o $(EXE)
	@ ./exec

blink: bonus
	gcc $(BFLAGS) main_bonus.c $(BNAME) -o $(BEXE)
	@ ./bexec

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(BNAME) $(EXE) $(BEXE)

re: fclean $(NAME)

bre: fclean bonus

.PHONY: clean fclean re