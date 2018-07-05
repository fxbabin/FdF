# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 22:51:42 by fbabin            #+#    #+#              #
#    Updated: 2018/07/04 19:55:09 by fbabin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF				=	fdf

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address

_SRCS			=	fdf.c get_coords.c test.c \

_LIBFT			=	libft.a
HEADER_DIR		=	includes
HEADER			=	$(HEADER_DIR)/fdf.h

SRCS_DIR		=	srcs
LIB_DIR			=	libft
SRCS			=	$(addprefix $(SRCS_DIR)/, $(_SRCS))
LIBFT			=	$(addprefix $(LIB_DIR)/, $(_LIBFT))
OBJS			=	$(SRCS:.c=.o)

#COLORS
_CYAN=\x1b[36m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_END=\x1b[0m

all: $(FDF)

$(FDF): $(HEADER) $(LIBFT) $(MLX) $(OBJS)
		@$(CC) $(CFLAGS) -o $(FDF) $(OBJS) -I /usr/local/include -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft -I $(HEADER_DIR)
		@echo "$(FDF) : $(_GREEN)Done$(_END)"

$(MLX):
		@make -C $(MLX_DIR)

$(LIBFT):
		@make -C $(LIB_DIR)

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR) -I libft/includes

clean:
		@make fclean -C $(LIB_DIR)
		@/bin/rm -f $(OBJS)
		@echo "$(FDF) clean : $(_GREEN)Done$(_END)"

fclean: clean
		@/bin/rm -f $(FDF)
		@echo "$(FDF) fclean : $(_GREEN)Done$(_END)"

re:
		@make fclean
		@make

.PHONY: all clean fclean re
