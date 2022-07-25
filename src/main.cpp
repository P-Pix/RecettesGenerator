#include "../include/includes.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    initListOfRecettes();
    Recette recette("recettes/hamburger.csv");
    Ingredient viandes(INGREDIENT_VIANDE_FILE);
    Ingredient fruits(INGREDIENT_FRUIT_FILE);
    Ingredient laitages(INGREDIENT_LAITAGE_FILE);
    Ingredient legumes(INGREDIENT_LEGUMES_FILE);
    Ingredient feculents(INGREDIENT_FECULENTS_FILE);
    fruits.addAnIngredient("orange");
    char letter = ' ';
    while (letter != 'e') {
        std::cout << "Veuillez choisir une lettre :" << std::endl;
        std::cin >> letter;
        if (letter == 'v') {
            std::cout << viandes << std::endl;
        } else if (letter == 'f') {
            std::cout << fruits << std::endl;
        } else if (letter == 'l') {
            std::cout << laitages << std::endl;
        } else if (letter == 'g') {
            std::cout << legumes << std::endl;
        } else if (letter == 'd') {
            std::cout << feculents << std::endl;
        } else if (letter == 'r') {
            std::cout << recette << std::endl;
        } else if (letter == 'e') {
            std::cout << "Au revoir !" << std::endl;
        } else {
            std::cout << "Cette lettre n'existe pas." << std::endl;
        }
    }
    return 0;
}