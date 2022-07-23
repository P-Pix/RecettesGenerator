#include "../include/Ingredient.hpp"

Ingredient::Ingredient(void) {
}

Ingredient::Ingredient(const std::string file) {
    this->readFile(file);
}

Ingredient::Ingredient(const char *file) {
    this->readFile(file);
}

Ingredient::~Ingredient(void) {
    delete[] this->m_listeIngredients;
}

void Ingredient::readFile(const std::string file) {
    system(std::string("sort -b -o " + file + " " + file).c_str());
    //system("for i in $(ls ingredients/); do sort -b -o ingredients/$i ingredients/$i; done");
    if (file.find(".txt") == std::string::npos) {
        std::cout << "Erreur : le fichier n'est pas un fichier txt" << std::endl;
        return;
    }

    // On ouvre le fichier et in creer le vector tmp
    std::ifstream fichier(file);
    std::string ligne;
    std::vector<std::string> liste;

    // On lit le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        try {
            liste.push_back(ligne);
            this->m_nombreIngredients++;
        } catch (std::exception &e) {
            std::cout << "Erreur : " << e.what() << std::endl;
        }
    }

    // Création du tableau dynamique
    this->m_listeIngredients = new std::string[this->m_nombreIngredients];
    for (int i = 0; i < this->m_nombreIngredients; i++) {
        this->m_listeIngredients[i] = liste[i];
    }

    // Libération de la mémoire
    fichier.close();
}

int Ingredient::getNombreIngredients(void) const {
    return this->m_nombreIngredients;
}

std::string Ingredient::getIngredient(int index) const {
    if (index < 0 || index >= this->m_nombreIngredients) {
        std::cout << "Erreur : l'index " << index << " est hors de la liste" << std::endl;
        return "";
    }
    return this->m_listeIngredients[index];
}

void Ingredient::print(void) const {
    for (int i = 0; i < this->m_nombreIngredients; i++) {
        std::cout << this->m_listeIngredients[i] << std::endl;
    }
}

/*
std::ofstream &operator<<(std::ofstream &os, const Ingredient &ingredient) {
    for (int i = 0; i < ingredient.getNombreIngredients(); i++) {
        os << ingredient.getIngredient(i) << std::endl;
    }
    return os;
}
*/