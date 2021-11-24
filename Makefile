NAME = push_swap

HEADER_DIR = ./includes/header.h

SOURCE_DIR = ./src

LIBFT_DIR = ./libs/libft

LIBFT_LIB = ${LIBFT_DIR}/libft.a

SOURCE_FILES = src/main.c src/prints.c
SOURCE_FILES += src/validate.c src/stack.c
SOURCE_FILES += src/utils.c src/swap.c src/push.c
SOURCE_FILES += src/rotates.c
SOURCE_FILES += src/small_sort.c
SOURCE_FILES += src/sort.c

RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror -g3

# SOURCES = $(addprefix $(SOURCE_DIR)/, $(SOURCES_FILES))

OBJECTS_CLT = ${SOURCE_FILES:.c=.o}
OBJECTS_SRV = ${SOURCES_FILES_SERVER:.c=.o}

MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

all: ${NAME} ${HEADER_DIR}

$(NAME): ${LIBFT_LIB} ${OBJECTS_CLT}
	${CC} ${CFLAGS} ${OBJECTS_CLT} ${LIBFT_LIB} -o ${NAME}
	${MSG1}

${LIBFT_LIB}:
	@${MAKE} -C ${LIBFT_DIR}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM}	${OBJECTS_CLT} ${OBJECTS_SRV}
	@${MAKE} fclean -C ${LIBFT_DIR}
	${MSG2}

fclean: clean
	${RM} ${NAME}
	@${MAKE} fclean -C ${LIBFT_DIR}

run:
	${MAKE} && ./so_long.a
	${MSG1}

normiall:
	norminette ${SOURCE_DIR}
	norminette ${HEADER_DIR}

# Regenerate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
