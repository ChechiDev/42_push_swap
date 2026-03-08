# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 16:50:46 by sperez-l          #+#    #+#              #
#    Updated: 2026/03/03 13:44:58 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
DNAME       := dbg_push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I./include -I./libft/include

SRC_DIR     := src
LIBFT_DIR   := ./libft
LIBFT       := $(LIBFT_DIR)/libft.a

LDFLAGS     := -L$(LIBFT_DIR)
LDLIBS      := -lft

# Recoge todos los .c de src/ recursivamente, excluyendo tests/
SRCS_ROOT   := push_swap.c

SRCS_SRC    := $(shell find $(SRC_DIR) -name '*.c' -not -path '*/tests/*')

SRCS        := $(SRCS_ROOT) $(SRCS_SRC)

OBJS_DIR    := objs
OBJS_ROOT   := $(SRCS_ROOT:%.c=$(OBJS_DIR)/%.o)
OBJS_SRC    := $(SRCS_SRC:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS        := $(OBJS_ROOT) $(OBJS_SRC)

ifeq ($(DEBUG),1)
	CFLAGS    += -ggdb3
	BUILD_MSG := Compiling debug:
else
	CFLAGS    += -O2
	BUILD_MSG := Compiling:
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nPUSH_SWAP COMPILED!\n"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

debug: DEBUG=1
debug: $(DNAME)

$(DNAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nPUSH_SWAP DEBUG COMPILED!\n"

$(OBJS_DIR)/%.o: %.c Makefile include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "$(BUILD_MSG) $<"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c Makefile include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "$(BUILD_MSG) $<"

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\nLIBFT CLEANED\n"

fclean: clean
	@rm -f $(NAME) $(DNAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\nLIBFT FULL CLEANED\n"

re: fclean all

.PHONY: all clean fclean re debug
