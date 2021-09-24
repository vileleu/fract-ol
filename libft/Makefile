BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

SRCS		= $(wildcard ./*.c)

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

HEADERS		= ./

FLAGS		= -Wall -Wextra -Werror

COMP		= 1

.c.o:		
			@echo "$(BLUE)\b->\c"
			@gcc ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o} > /dev/null
			@echo "$(RESET)\c"

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@echo "\n$(GREEN)[libft done][✔]$(BLUE)"

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean re all bonus
