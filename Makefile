

NAME = pipex

all:
	@cc *.c execution/*.c parsing/*.c libft/*.c -o $(NAME)
	@echo "compiling ..."
	
clean:
	@rm -fr $(NAME)
	
fclean: clean
