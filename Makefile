# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:39:01 by mpascaud          #+#    #+#              #
#    Updated: 2017/12/12 20:49:46 by mpascaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit.a

TAGS = -Wall -Werror -Wextra

SRC = ft_putchar.c ft_putstr.c ft_memcpycpy.c \
	  validite.c construction.c carredepart.c placelibre.c afficherliste.c \
	  placement.c agencement.c dimensionnement.c \

BIN = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(TAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

clean :
	rm -rf $(BIN)

fclean : clean
	rm -rf $(NAME)

re : fclean all
