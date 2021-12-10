# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 20:22:14 by anolivei          #+#    #+#              #
#    Updated: 2021/11/24 23:28:38 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = sources
OBJ_DIR = .objs

SRC =	$(SRC_DIR)/actions.c \
		$(SRC_DIR)/handling_errors.c \
		$(SRC_DIR)/handling_forks.c \
		$(SRC_DIR)/handling_philos.c \
		$(SRC_DIR)/handling_threads.c \
		$(SRC_DIR)/handling_time.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/philo_utils.c \
		$(SRC_DIR)/routine.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving philo\033[0m"

re: fclean all

.PONY: all clean fclean re
