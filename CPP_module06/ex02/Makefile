# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 13:15:17 by yfontene          #+#    #+#              #
#    Updated: 2025/01/06 22:33:12 by yfontene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN				=	\033[0;32m
RED					=	\033[0;31m
YELLOW				=	\033[0;33m
MAGENTA				=	\033[0;35m
CYAN				=	\033[0;36m
END					=	\033[0m


NAME = base
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS=					main.cpp\
						Base.cpp
						
OBJS=					$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)succesfully compiled! ✅$(END)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	@$(RM) $(OBJS) 

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)deleted! 🚮$(END)"

re: fclean all

.PHONY: all clean fclean re
