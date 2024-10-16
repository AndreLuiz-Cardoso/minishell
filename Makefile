# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-fif <luis-fif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 12:17:33 by luis-fif          #+#    #+#              #
#    Updated: 2024/10/16 09:38:26 by luis-fif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do programa
NAME = minishell

# Caminhos
SRC_DIR = src
OBJ_DIR = utils
INCLUDE_DIR = includes
LIBFT_DIR = libft

# Arquivos fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Flags de compilação
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
CFLAGS = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) #nao esquecer de trocar -Wall etc

# Biblioteca
LIBFT = $(LIBFT_DIR)/libft.a
READLINE = -lreadline

# Regras
all: $(NAME)

# Compilar o programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE)

# Compilar os arquivos .o e colocá-los na pasta utils/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar a pasta utils se ela não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpar os arquivos compilados
clean:
	rm -rf $(OBJ_DIR)/*.o

# Limpar tudo (inclui o binário do programa)
fclean: clean
	rm -f $(NAME)

# Recompilar tudo
re: fclean all

# Não considera esses nomes como arquivos
.PHONY: all clean fclean re

