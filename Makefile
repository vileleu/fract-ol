BLUE = 		\033[0;34m
GREEN = 	\033[0;32m
LIGHTBLUE = \033[1;34m
RED = 		\033[0;31m
YELLOW = 	\033[1;33m
ORANGE = 	\033[0;33m
MAGENTA = 	\033[0;35m
RESET = 	\033[0m

SRCS		= $(wildcard srcs/*.c)

OBJS		= ${SRCS:.c=.o}

NAME		= fract-ol

INCLUDES	= -I includes/ -I libft/ -I minilibx-linux/

LIBFT		= libft/

MLX			= minilibx-linux/

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

FLAGS_X		= -lmlx -lm -lXext -lX11 -lpthread -lbsd

.c.o:		
			@gcc ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o} > /dev/null

${NAME}:	${OBJS}
			@printf "\n$(BLUE)"
			@make -C ${LIBFT}
			@make -C ${MLX} > /dev/null
			@printf "$(BLUE)Compiling files..."
			@gcc ${FLAGS} ${OBJS} ${LIBFT}/libft.a ${MLX}/libmlx.a -o ${NAME} -L ${FLAGS_X}
			@printf "$(GREEN)[${NAME} done][✔]$(RESET)"
			@printf "\n\n"

all:		${NAME}

clean:
			@printf "\n"
			@printf "$(RED)clean libft\n"
			@make -C ${LIBFT} clean
			@printf "Erase files '.o'\n"
			@rm -rf $(OBJS)
			@printf "\033[0m\n"

fclean:
			@printf "\n"
			@printf "$(RED)clean libft\n"
			@make -C ${LIBFT} fclean
			@printf "clean libmlx\n"
			@make -C ${MLX} clean > /dev/null
			@printf "Erase files '.o'\n"
			@rm -rf $(OBJS)
			@printf "$(RED)Delete executable and libft\n"
			@rm -rf ${NAME}
			@printf "$(RESET)\n"

re:			fclean all

.PHONY:		clean fclean re all