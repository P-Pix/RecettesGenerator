#include "../include/includes.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    std::map<float, bool> values;
    values[0.0] = NEGATIVE;
    values[0.5] = NEGATIVE;
    values[1.0] = NEGATIVE;
    values[1.5] = NEGATIVE;
    values[6.0] = POSITIVE;
    values[6.5] = POSITIVE;
    values[7.0] = POSITIVE;
    values[7.5] = POSITIVE;
    values[8.0] = POSITIVE;
    std::cout << "values[0.0] = " << values[0.0] << std::endl;
    std::cout << "values[1.0] = " << values[1.0] << std::endl;
    std::cout << "values[2.0] = " << values[2.0] << std::endl;
    std::cout << "values[3.0] = " << values[3.0] << std::endl;
    std::cout << "values[4.0] = " << values[4.0] << std::endl;
    std::cout << "values[5.0] = " << values[5.0] << std::endl;
    std::cout << "values[6.0] = " << values[6.0] << std::endl;
    std::cout << "values[7.0] = " << values[7.0] << std::endl;
    std::cout << "values[8.0] = " << values[8.0] << std::endl;
    IAGraphique ia(4, "test");
    ia.train(values);
    /*
    initListOfRecettes();
    Recette::addRecette();
    Recette recette("recettes/pates_carbonara.csv");
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
    */
    return 0;
}