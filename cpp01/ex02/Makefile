# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 17:23:49 by kpineda-          #+#    #+#              #
#    Updated: 2025/10/15 20:12:43 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

# Archivos fuente y objetos
SRC = main.cpp
OBJ_DIR = obj
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Compilador y flags
CC = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;34m"
	@echo " _____        ___ ___ "
	@echo "|   __|_ _   |   |_  |"
	@echo "|   __|_'_|  | | |  _|"
	@echo "|_____|_,_|  |___|___|"
	@echo "\033[0m"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;34m⚙️  Compilando $<...\033[0m"
	@$(CC) $(CPPFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "\033[0;35m🧹 Limpiando archivos objeto...\033[0m"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "\033[0;35m🗑️  Eliminando ejecutable...\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
