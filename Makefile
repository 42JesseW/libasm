# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jevan-de <jevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/12 17:22:50 by jevan-de      #+#    #+#                  #
#    Updated: 2021/02/17 15:06:13 by jessevander   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a

CFLAGS =	-Wall

SRC =		ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

UNAME_S =	$(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	P = 			\x1b[35m
	B = 			\x1b[34m
	Y = 			\x1b[33m
	G = 			\x1b[32m
	R = 			\x1b[31m
	W = 			\x1b[0m
	SRCDIR =		osx
	ASMFLAGS =		-fmacho64
else ifeq ($(UNAME_S), Linux)
	P = 			\033[35m
	B = 			\033[34m
	Y = 			\033[33m
	G = 			\033[32m
	R = 			\033[31m
	W = 			\033[0m
	SRCDIR =		linux
	ASMFLAGS =		-felf64
	CFLAGS +=		-no-pie
endif

OBJ =		$(addprefix $(SRCDIR)/, $(SRC:.s=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(B)CREATING LIBASM LIBRARY...$(W)"
	@ar vrcs $@ $^
	@echo "\n$(G)SUCCESSFULLY CREATED LIBASM!$(W)"

%.o: %.s
	@echo "$(Y)Compiling $< to $@...$(W)"
	@nasm $(ASMFLAGS) $<

clean:
	@echo "$(R)Cleaning up obj files and random .txt files...$(W)"
	@rm -vf $(OBJ) file.txt

fclean: clean
	@echo "$(R)Cleaning up $(NAME)...$(W)"
	@rm -vf $(NAME)

test: all
	@echo "$(P)Compiling test program for libasm...$(W)"
	@$(CC) $(CFLAGS) main.c -L. -lasm -o test
	@echo "$(G)libasm test program compiled successfully!$(W)"
	@echo "$(Y)Running test...$(W)"
	@./test
	@echo "$(G)Successfully run test... Cleaning up...$(W)"
	@rm -vf test
	
re: fclean all

.PHONY: fclean clean re