# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 16:50:46 by sperez-l          #+#    #+#              #
#    Updated: 2026/02/19 18:13:38 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
DEGUB_NAME 	:= dbg_push_swap

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I./include -I./libft/include

LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a

LDFLAGS		:= -L$(LIBFT_DIR)
LDLIBS		:= -lft

SRCS		:= push_swap.c \
		   src/parse_options.c

OBJS_DIR	:= objs
OBJS		:= $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

# Default: release
ifeq ($(DEBUG),1)
	CFLAGS   += -ggdb3
	BUILD_MSG := Compiling debug:
else
	CFLAGS   += -O2
	BUILD_MSG := Compiling:
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nPUSH_SWAP COMPILED!\n"

# Build libft only when needed (and only if files changed)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Debug build: force DEBUG=1 for this target
debug: DEBUG=1
debug: $(DNAME)

$(DNAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nPUSH_SWAP DEBUG COMPILED!\n"

$(OBJS_DIR)/%.o: srcs/%.c Makefile include/push_swap.h
	@mkdir -p $(OBJS_DIR)
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
