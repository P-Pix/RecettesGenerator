#include "../include/Recette.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    Recette recette("recettes/hamburger.csv");
    std::cout << recette << std::endl;
    return 0;
}