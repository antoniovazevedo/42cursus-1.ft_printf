SRCS	= $(wildcard srcs/*.c)
# SRCS	= srcs/char.c srcs/string.c srcs/int.c srcs/aux.c srcs/main.c

OBJS	= ${SRCS:.c=.o}

INCDIR	= includes
NAME	= libftprintf.a
AR		= ar -rcs
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	${NAME}

${NAME}:libft.a ${OBJS}
		cp libft/libft.a libftprintf.a
		${AR} ${NAME} ${OBJS}

bonus: ${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o $@ -I ${INCDIR}

libft.a:	
		make libft.a -C ./libft

clean:
		make clean -C ./libft
		${RM} libft.a
		${RM} *.o
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
