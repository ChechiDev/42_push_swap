# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 16:50:46 by sperez-l          #+#    #+#              #
#    Updated: 2026/02/24 13:30:46 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
DNAME       := dbg_push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I./include -I./libft/include

SRC_DIR     := src
CHECK_DIR   := $(SRC_DIR)/check
PARSE_DIR   := $(SRC_DIR)/parse
MOV_DIR     := $(SRC_DIR)/movement
ALGO_DIR    := $(SRC_DIR)/algorithm
UTILS_DIR   := $(SRC_DIR)/utils

LIBFT_DIR   := ./libft
LIBFT       := $(LIBFT_DIR)/libft.a

LDFLAGS     := -L$(LIBFT_DIR)
LDLIBS      := -lft

# Sources (root + src/)
SRCS_ROOT   := push_swap.c
SRCS_SRC    := $(CHECK_DIR)/check_first.c \
	       $(CHECK_DIR)/check_flags.c \
	       $(CHECK_DIR)/check_options.c \
	       $(CHECK_DIR)/check_duplicates.c \
	       $(CHECK_DIR)/check_minmax.c \
	       $(CHECK_DIR)/check_num.c \
	       $(PARSE_DIR)/parse_num.c \
	       $(PARSE_DIR)/parse_params.c \
	       $(PARSE_DIR)/parse_options.c \
	       $(PARSE_DIR)/parse_disorder_index.c \
	       $(MOV_DIR)/push.c \
	       $(MOV_DIR)/rotate.c \
	       $(MOV_DIR)/swap.c \
	       $(MOV_DIR)/reverse_rotate.c \
	       $(UTILS_DIR)/free_list.c \
	       $(UTILS_DIR)/free_all.c \
	       $(UTILS_DIR)/add_node.c

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

# Compile .c from project root
$(OBJS_DIR)/%.o: %.c Makefile include/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "$(BUILD_MSG) $<"

# Compile .c from src/
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
