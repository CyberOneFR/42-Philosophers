# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 05:06:30 by ethebaul          #+#    #+#              #
#    Updated: 2025/06/27 17:34:33 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILD_DIR			=	./build/
HEADERS_DIR			=	./headers/
SRCS_DIR			=	./srcs/

MKCONFIGURE			=	./configure.mk
MKGENERATED			=	./generated.mk
MKCOLOR				=	./color.mk

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g3 -O3
LDLIBS				=	-lpthread

NAME				=	philo

all: normcheck $(NAME)
	@echo -e $(GREEN)Successfully Built $(NAME)$(RESET)

-include $(MKCONFIGURE) $(MKGENERATED) $(MKCOLOR)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJS) $(LDLIBS)
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

normcheck:
	@echo -e -n $(RED)
	@norminette | grep "Error:" || echo $(GREEN)Norminette: OK
	@echo -e -n $(RESET)

clangd: 
	@echo $(CC) $(CFLAGS) $(HEADERS) -o $(NAME) $(SRCS) $(LDLIBS) | compiledb

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY : all clean fclean re clangd normcheck