# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 14:28:30 by ymatsui           #+#    #+#              #
#    Updated: 2024/01/09 17:54:37 by ymatsui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = libftprintf

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_char.c ft_print_str.c ft_print_address.c ft_print_decimal.c ft_print_integer.c ft_print_unsigned_decimal.c ft_print_hex_lower.c ft_print_hex_upper.c ft_print_percent.c
BONUS = 
OBJS = $(SRCS:.c=.o)
OBJB = $(BONUS:.c=.o)
ifdef BONUS_FLAG
	OBJS += $(OBJB)
endif

all: $(NAME) $(EXEC)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(EXEC): $(MAIN) $(NAME)
	@$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	@make BONUS_FLAG=1 all

.PHONY: all clean fclean re bonus