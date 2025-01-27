# Executables
NAME = pipex

# Source files and Vars
SRC = \
	libft/ft_decode.c  libft/ft_encode.c  libft/ft_split.c libft/ft_strdup.c \
	libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
	parsing/parse_data.c parsing/get_path.c parsing/error.c \
	utils/dup2_and_close.c \
	child1.c child2.c create_children.c create_pipe.c \
	main.c

OBJ = $(SRC:.c=.o)
INC = parsing/parsed_data.h parsing/parsing.h libft/libft.h pipex.h

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[Compiling $<]"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "[$@ is Created]"

clean:
	@rm -fr $(OBJ)
	@echo "[cleaning object files...]"
	
fclean: clean
	@rm -fr $(NAME)
	@echo "[cleaning executable...]"

re: fclean all
