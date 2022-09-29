# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyammoun <pyammoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:10:36 by pyammoun          #+#    #+#              #
#    Updated: 2022/08/31 16:22:34 by pyammoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	${addprefix src/, main.c utils.c creation.c execution.c checker.c cleaner.c}
OBJS        =	${SRCS:.c=.o}
NAME        =	philo
AR    		=	ar rcs
GCC       	=	gcc 
RM       	=	rm -f
CFLAGS    	=	-Wall -Wextra -Werror -g

all:	$(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):    $(OBJS)

			$(GCC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:        clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
