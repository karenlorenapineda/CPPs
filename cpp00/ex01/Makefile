# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:27:12 by kpineda-          #+#    #+#              #
#    Updated: 2025/10/13 20:18:12 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Phonebook

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Nombres base de los archivos fuente
FILES = PhoneBook.cpp Contact.cpp main.cpp

# Archivos fuente y objetos (con rutas)
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

# Compilador y flags
CC = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;34m"
	@echo " _____        ___ ___   "
	@echo "|   __|_ _   |   |_  |  "
	@echo "|   __|_'_|  | | |_| |_ "
	@echo "|_____|_,_|  |___|_____|"
	@echo "\033[0m"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
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
