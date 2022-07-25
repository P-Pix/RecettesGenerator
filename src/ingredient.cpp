#include "../include/Ingredient.hpp"

Ingredient::Ingredient(void) {
}

Ingredient::Ingredient(const std::string file) {
    this->m_FileName = file;
    this->readFile();
}

Ingredient::Ingredient(const char *file) {
    this->m_FileName = file;
    this->readFile();
}

Ingredient::~Ingredient(void) {
    delete[] this->m_listeIngredients;
}

void Ingredient::readFile(void) {
    system(std::string("sort -b -o " + this->m_FileName + " " + this->m_FileName).c_str());
    if (this->m_FileName.find(".txt") == std::string::npos) {
        std::cout << "Erreur : le fichier n'est pas un fichier txt" << std::endl;
        return;
    }

    // On ouvre le fichier et in creer le vector tmp
    std::ifstream fichier(this->m_FileName);
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

    if (this->m_listeIngredients != nullptr) {
        delete[] this->m_listeIngredients;
    }

    // Création du tableau dynamique
    this->m_listeIngredients = new std::string[this->m_nombreIngredients];
    for (int i = 0; i < this->m_nombreIngredients; i++) {
        if (liste[i] == "") {
            continue;
        }
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

void Ingredient::addAnIngredient(const std::string ingredient) {
    if (this->m_FileName.find(".txt") == std::string::npos) {
        std::cout << "Erreur : le fichier n'est pas défini" << std::endl;
        return;
    }
    std::ofstream fichier(this->m_FileName, std::ios::app);
    // transferer le contenu du fichier dans un string
    std::ifstream file(this->m_FileName);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(ingredient) != std::string::npos) {
            std::cout << "Erreur : l'ingrédient " << ingredient << " existe déjà" << std::endl;
            return;
        }
    }
    fichier << ingredient << std::endl;
    fichier.close();
    file.close();
    this->readFile();
}