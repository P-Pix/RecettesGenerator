#/bin/bash

# Makefile can't refuse to execute these commands.
.PHONY: all run clean mrproper named

# Color
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
YELLOW='\033[0;33m'

# when user write make
.DEFAULT_GOAL := help

# for all file .cpp in the directory src/
SRC	= $(wildcard src/*.cpp)

# Transform all file .cpp in the directory src/ in file .o
OBJ	= $(SRC:.cpp=.o)

# Compilator
CC = g++

# Name Executable
NAME = Recette
CFLAGS =	
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
LDFLAGS	=

all: $(NAME) clean ## Compile link and clean all .o file

$(NAME): $(OBJ) ## Compile and link
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

run: ## Execute the executable
	@./$(NAME)

help: ## Affiche la liste des commandes
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}'

named: ## List all file .cpp in the directory src/
	@echo "Name: $(SRC)"

%.o: src/%.cpp ## Compile the file into an object file
	$(CC) -c $< -o $@ $(CXXFLAGS)

clean:	## Vide les fichiers .o et le fichier executable
	@rm -rf $(OBJ)

mrproper: clean  ## Vide les fichiers .o et le fichier executable
	@rm -rf $(NAME)