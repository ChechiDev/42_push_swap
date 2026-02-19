# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 18:07:04 by sperez-l          #+#    #+#              #
#    Updated: 2026/02/19 18:06:41 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I./include

AR          := ar
ARFLAGS     := rcs
RM          := rm -f

SRC_DIR     := src
OBJ_DIR     := objs
INC_HDR     := include/libft.h

SRCS        := $(SRC_DIR)/ft_strcmp.c \
	       $(SRC_DIR)/ft_lstnew.c

OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo "\nLIBFT COMPILED!\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_HDR) Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@rmdir $(OBJ_DIR) 2>/dev/null || true
	@echo "\nLIBFT CLEANED\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\nLIBFT FULL CLEANED\n"

re: fclean all

.PHONY: all clean fclean re
