# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 16:20:56 by sperez-l          #+#    #+#              #
#    Updated: 2026/02/25 17:36:36 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Lista de ejecutables de test (uno por cada fichero .c en tests/)
TEST_SRCS  := $(wildcard *.c)
TEST_BINS  := $(patsubst %.c,%,$(TEST_SRCS))

# Compilador y banderas
CC      ?= cc
CFLAGS  := -Wall -Wextra -Werror
ifdef DEBUG
  CFLAGS += -ggdb3
else
  CFLAGS += -O2
endif

# Rutas a las cabeceras del proyecto y de libft
CPPFLAGS := -I../include -I../libft/include

# Librería libft
LIBFT_DIR := ../libft
LIBFT     := $(LIBFT_DIR)/libft.a

# Fuentes del proyecto necesarias para los tests
# (Asegúrate de NO incluir archivos que definan `main()`, como push_swap.c)
PS_SRCS := \
  ../src/check/check_flags.c \
  ../src/check/check_options.c \
  ../src/check/check_num.c \
  ../src/check/check_duplicates.c \
  ../src/check/check_minmax.c \
  ../src/check/check_first.c \
  ../src/parse/parse_options.c \
  ../src/parse/parse_params.c \
  ../src/parse/parse_disorder_index.c \
  ../src/utils/add_node.c \
  ../src/utils/free_list.c \
  ../src/utils/free_all.c

# Directorio de objetos (local a tests/)
OBJDIR := .objs

# Objetos del proyecto compilados una sola vez
PS_OBJS := $(patsubst ../%.c,$(OBJDIR)/%.o,$(PS_SRCS))

all: $(LIBFT) $(PS_OBJS) $(TEST_BINS)

# Link de cada test. El ejecutable tendrá el mismo nombre que el .c
%: %.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[TEST COMPILADO] $@"

# Compilación de objetos del proyecto a .objs/...
$(OBJDIR)/%.o: ../%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilar libft si no existe
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(TEST_BINS)
	$(RM) -r $(OBJDIR)
	@echo "\nTESTS LIMPIADOS\n"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\nLIBFT LIMPIADA\n"

re: fclean all

.PHONY: all clean fclean re
