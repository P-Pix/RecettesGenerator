#include "../include/includes.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    std::map<std::map<float, float>, bool> values;
    std::map<float, float> values1; // true
    std::map<float, float> values2; // true
    std::map<float, float> values3; // false
    std::map<float, float> values4; // false

    values1[0] = 0;
    values1[1] = 0;

    values2[0] = 0;
    values2[1] = 1;

    values3[0] = 1;
    values3[1] = 0;

    values4[0] = 1;
    values4[1] = 1;
    values[values1] = NEGATIVE;
    values[values2] = NEGATIVE;
    values[values3] = POSITIVE;
    values[values4] = POSITIVE;
    IAGraphique ia(2, "test");
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