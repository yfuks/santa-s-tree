#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/26 14:49:48 by yfuks             #+#    #+#              #
#    Updated: 2015/05/26 14:49:58 by yfuks            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	Santa_tree

CC		=	clang

CFLAGS	+=	-Wall -Wextra -Werror

SRC		=	$(shell ls -1 sources)

INC		=	-I includes/

OBJ		=	$(patsubst %.c, obj/%.o, $(SRC))

LIB		= 	-lncurses

LIBFT	= libft/libft.a

ifeq ($(BUILD),d)
    CFLAGS += -g
endif
ifeq ($(BUILD),o)
    CFLAGS += -03
endif

OS = $(shell uname -s)

ECHO = echo

ifeq ($(OS),Linux)
    ECHO += -e
endif

RM		=	/bin/rm -rf

all		=	$(NAME)

$(NAME): obj $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(LIBFT) -o $@ $(OBJ) $(LIB)

obj/%.o:	sources/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@$(ECHO) "[\033[1;32m√\033[m]" $@

obj:
	@mkdir -p obj

clean:
	@make -C libft/ clean
	@$(ECHO) "\033[33;31mCleaning files .o ...\033[0m"
	@$(RM) obj/

fclean: clean
	@make -C libft/ fclean
	@$(ECHO) "\033[33;31mCleaning executables...\033[0m"
	@$(RM) $(NAME)

norme:
	norminette $(SRC) $(INC)

re: fclean $(NAME)