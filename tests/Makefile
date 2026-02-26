# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 16:20:56 by sperez-l          #+#    #+#              #
#    Updated: 2026/02/26 17:00:18 by sperez-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       := cc
CFLAGS   := -Wall -Wextra -Werror
CPPFLAGS := -I../include -I../libft/include

LIBFT_DIR := ../libft
LIBFT     := $(LIBFT_DIR)/libft.a

OBJDIR    := .objs

# ── Fuentes del proyecto (sin main) ──────────────────────────────────────────

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
	../src/utils/print_stack.c \
	../src/utils/free_list.c \
	../src/utils/free_all.c

PS_OBJS := $(patsubst ../%.c, $(OBJDIR)/%.o, $(PS_SRCS))

# ── Descubrimiento de tests por subcarpeta ───────────────────────────────────

CHECK_SRCS  := $(wildcard test_check/*.c)
LIBFT_SRCS  := $(wildcard test_libft/*.c)
ALGO_SRCS   := $(wildcard test_algo/*.c)
MOV_SRCS    := $(wildcard test_mov/*.c)
PARSE_SRCS  := $(wildcard test_parse/*.c)
UTILS_SRCS  := $(wildcard test_utils/*.c)

ALL_SRCS    := $(CHECK_SRCS) $(LIBFT_SRCS) $(ALGO_SRCS) \
               $(MOV_SRCS) $(PARSE_SRCS) $(UTILS_SRCS)

# Cada .c genera un binario en la misma subcarpeta (sin extensión)
ALL_BINS    := $(patsubst %.c, %, $(ALL_SRCS))

# ── Reglas ───────────────────────────────────────────────────────────────────

all: $(LIBFT) $(PS_OBJS) $(ALL_BINS)

# Los tests de libft solo necesitan libft, no los objetos del proyecto
test_libft/%: test_libft/%.c $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

# El resto de tests necesitan libft + objetos del proyecto
test_check/%: test_check/%.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

test_algo/%: test_algo/%.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

test_mov/%: test_mov/%.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

test_parse/%: test_parse/%.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

test_utils/%: test_utils/%.c $(LIBFT) $(PS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(PS_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@echo "[OK] $@"

# Compilar objetos del proyecto
$(OBJDIR)/%.o: ../%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilar libft si no existe
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Ejecutar todos los tests compilados
run: all
	@echo "\n=== RESULTADOS ===\n"
	@for bin in $(ALL_BINS); do \
		echo "--- $$bin ---"; \
		./$$bin; \
		echo ""; \
	done

clean:
	$(RM) $(ALL_BINS)
	$(RM) -r $(OBJDIR)
	@echo "\nTESTS LIMPIADOS\n"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\nLIBFT LIMPIADA\n"

re: fclean all

.PHONY: all run clean fclean re
