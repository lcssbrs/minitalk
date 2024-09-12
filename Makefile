PROG	= server
PROG2	= client
SRCS 	= servers/server.c
SRCS2	= clients/client.c
OBJS 	= ${SRCS:.c=.o}
OBJS2	= ${SRCS2:.c=.o}

HEADER	= -Iinclude

CC 		= gcc
#CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER}-I/usr/include -c $< -o $(<:.c=.o)

all: 		${PROG} ${PROG2}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./Libft
					@make re -C ./printf
					@$(CC) ${OBJS} -LLibft -lft -Lprintf -lprintf -o ${PROG}
					@echo "\033[32mServer Compiled!"

${PROG2}:	${OBJS2}
					@$(CC) ${OBJS2} -LLibft -lft -Lprintf -lprintf -o ${PROG2}
					@echo "\033[32mClient Compiled!"

clean:
					@make clean -C ./Libft
					@make clean -C ./printf
					@rm -f ${OBJS} ${OBJS2}

fclean: 	clean
					@make fclean -C ./Libft
					@make fclean -C ./printf
					@rm -f $(PROG2)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!"

re:			fclean all

.PHONY: all clean fclean re
