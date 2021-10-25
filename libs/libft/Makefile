NAME = libft.a

# Add more files to sources
SOURCES = ft_strlen.c ft_itoa.c ft_strchr.c
SOURCES += ft_putchar_fd.c ft_putstr_fd.c
SOURCES += ft_strdup.c ft_strlcpy.c ft_atoi.c
SOURCES += ft_isdigit.c ft_atol.c

# Use same files from sources, but change .c to .o
OBJECTS = ${SOURCES:.c=.o}

# @ supress commands to show in terminal
RM = @rm -f

CC = @clang

CFLAGS = -Wall -Wextra -Werror
MSG1 = @echo "Compiled ✔︎"
MSG2 = @echo "Cleaned ✔︎"

# Adds object files *.o static library libft.a, creating libft.a if it no exist.
ARCHIVE = @ar -rc

# Create an index for the library
RANLIB = @ranlib

# Compile files following above rules 	${CC} -o ${NAME} ${OBJECTS}
$(NAME): ${OBJECTS}
	${ARCHIVE} ${NAME} ${OBJECTS}
	${RANLIB} ${NAME}
	${MSG1}

# Default all command to compile
all: ${NAME}

# Clean generated .o files
clean:
	${RM} ${OBJECTS}
	${MSG2}

# Force clean all files generated on all
fclean: clean
	${RM} ${NAME}

# Regenarate compilation
re: fclean all

# phony will run, independent from the state of the file system, avoid make in files with same name
.PHONY: all clean fclean re
