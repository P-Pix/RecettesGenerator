#include "../include/Recette.hpp"

Recette::Recette(void) {
}

Recette::Recette(const std::string file) {
    readFile(file);
}

Recette::Recette(const char *file) {
    readFile(std::string(file));
}

Recette::~Recette(void) {
    delete[] m_listeQuantites;
    delete[] m_listeIngredients;
    delete[] m_listeOptionnels;
}

void Recette::readFile(const std::string file) {
    if (file.find(".csv") == std::string::npos) {
        std::cout << "Erreur: le fichier n'est pas un fichier csv" << std::endl;
        return;
    }

    /// créer des conteneur temporaires pour les données lues du fichier
    std::vector<int> quantites;
    std::vector<std::string> ingredients;
    std::vector<bool> optionnels;

    // overture du fichier csv
    std::ifstream fichier(file);
    if (!fichier) {
        std::cout << "Erreur: le fichier n'a pas pu être ouvert" << std::endl;
        return;
    }
    std::string ligne;

    // lecture du fichier csv
    while (getline(fichier, ligne)) {
        try {
            size_t pos = ligne.find(',');
            quantites.push_back(std::stoi(ligne.substr(0, pos)));
            ligne.erase(0, pos + 1);
            pos = ligne.find(',');
            ingredients.push_back(ligne.substr(0, pos));
            ligne.erase(0, pos + 1);
            optionnels.push_back(ligne.substr(0, pos) == "0");
            ligne.erase(0, pos + 1);
            if (ligne.size() > 0) {
                throw std::invalid_argument("Erreur: le fichier csv est mal formé");
            }
        } catch (std::exception &e) {
            std::cout << "Erreur: " << e.what() << std::endl;
            return;
        }
        this->m_nombreIngredients++;
    }

    // copie des données dans les attributs de la classe
    this->m_listeQuantites = new int[quantites.size()];
    this->m_listeIngredients = new std::string[ingredients.size()];
    this->m_listeOptionnels = new bool[optionnels.size()];
    for (size_t i = 0; i < quantites.size(); i++) {
        this->m_listeQuantites[i] = quantites[i];
        this->m_listeIngredients[i] = ingredients[i];
        this->m_listeOptionnels[i] = optionnels[i];
    }

    // fermeture du fichier csv
    fichier.close();
}

std::ostream &operator<<(std::ostream &os, const Recette &recette) {
    for (int i = 0; i < recette.m_nombreIngredients; i++) {
        os  << recette.m_listeQuantites[i] << " "
            << recette.m_listeIngredients[i] << " "
            << (recette.m_listeOptionnels[i] ? "O" : "X") 
            << std::endl;
    }
    return os;
}