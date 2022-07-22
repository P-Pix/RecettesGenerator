#include "../include/includes.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    initListOfRecettes();
    Recette recette("recettes/hamburger.csv");
    Ingredient viandes("ingredients/viandes.txt");
    std::cout << recette << std::endl;
    viandes.print();
    return 0;
}