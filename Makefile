#/bin/bash

.PHONY: all run clean mrproper named

# Color
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
YELLOW='\033[0;33m'

.DEFAULT_GOAL := help

SRC	=	$(wildcard src/*.cpp)
OBJ	=	$(SRC:.cpp=.o)
CC	=	g++
NAME	=	Recette
CFLAGS	=	
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++11
LDFLAGS	=

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

run:
	@./$(NAME)

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}'

named:
	@echo "Name: $(SRC)"

%.o: src/%.cpp ## Compile the file into an object file
	$(CC) -c $< -o $@ $(CXXFLAGS)

clean:	## Vide les fichiers .o et le fichier executable
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(NAME)