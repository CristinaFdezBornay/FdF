# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 09:08:51 by ibaran            #+#    #+#              #
#    Updated: 2019/03/06 18:23:58 by ibaran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean

VPATH:= ./sources/ ./objects/ ./includes/

NAME := fdf

CC := gcc
FRAMEWORK := -framework OpenGL -framework AppKit
LIB := libft/libft.a minilibx_macos/libmlx.a
INCLUDES := -I minilibx_macos/ -I includes/ -I libft/
FLAGS := -Wall -Wextra -Werror

SRCS_PATH := ./sources/
OBJS_PATH := ./objects/
SRCS_NAME := \
main.c \
allocation.c \
helpers.c \
image_manipulation.c \
projections.c \
reader.c \
keys_1.c \
keys_2.c
OBJS_NAME := $(SRCS_NAME:.c=.o)

OBJS := $(patsubst %,$(OBJS_PATH)%,$(OBJS_NAME))

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo [CC] $<
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OBJS)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(FLAGS) -o $@ $^ $(LIB) $(FRAMEWORK)

clean:
	@echo "[Cleaning]"
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "[FCleaning]"
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
