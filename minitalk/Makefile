# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 10:55:33 by vzashev           #+#    #+#              #
#    Updated: 2023/08/27 19:14:10 by vzashev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_CLIENT = client
EXE_SERVER = server

FT_PRINTF = libftprintf.a

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I include

RM = rm -rf

all:	$(EXE_CLIENT) $(EXE_SERVER)

$(EXE_CLIENT) : $(OBJ_CLIENT)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(INCLUDES) ft_printf/$(FT_PRINTF) -o $(EXE_CLIENT)

$(EXE_SERVER): $(OBJ_SERVER)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(INCLUDES) ft_printf/$(FT_PRINTF) -o $(EXE_SERVER)

clean :
			@make clean -C ft_printf
			${RM} ${OBJ_CLIENT}
			${RM} ${OBJ_SERVER}

fclean : 	clean
			@make fclean -C ft_printf
			${RM} $(EXE_CLIENT)
			${RM} $(EXE_SERVER)
			${RM} $(FT_PRINTF)

re :		fclean all

.PHONY:		all clean fclean re
