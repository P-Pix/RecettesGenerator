#include "../include/Recette.hpp"

Recette::Recette(void) {
}

Recette::Recette(const std::string file) {
    this->readFile(file);
}

Recette::Recette(const char *file) {
    this->readFile(std::string(file));
}

Recette::~Recette(void) {
    delete[] this->m_listeQuantites;
    delete[] this->m_listeIngredients;
    delete[] this->m_listeOptionnels;
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

int Recette::getNombreIngredients(void) const {
    return this->m_nombreIngredients;
}

int Recette::getQuantite(int index) const {
    if (index < 0 || index >= this->m_nombreIngredients) {
        std::cout << "Erreur : l'index est hors de la liste" << std::endl;
        return -1;
    }
    return this->m_listeQuantites[index];
}

std::string Recette::getIngredient(int index) const {
    if (index < 0 || index >= this->m_nombreIngredients) {
        std::cout << "Erreur : l'index est hors de la liste" << std::endl;
        return "";
    }
    return this->m_listeIngredients[index];
}

bool Recette::getOptionnel(int index) const {
    if (index < 0 || index >= this->m_nombreIngredients) {
        std::cout << "Erreur : l'index est hors de la liste" << std::endl;
        return "";
    }
    return this->m_listeOptionnels[index];
}

std::ostream &operator<<(std::ostream &os, const Recette &recette) {
    for (int i = 0; i < recette.getNombreIngredients(); i++) {
        os  << recette.getQuantite(i) << " "
            << recette.getIngredient(i) << " "
            << (recette.getOptionnel(i) ? "O" : "X") 
            << std::endl;
    }
    return os;
}

std::vector<std::string> getListOfRecettes(void) {
    std::ifstream fichier("recettes/recettes.txt");
    if (!fichier) {
        std::cout << "Erreur: le fichier n'a pas pu être ouvert" << std::endl;
        return std::vector<std::string>();
    }
    std::string ligne;
    std::vector<std::string> liste;
    while (getline(fichier, ligne)) {
        liste.push_back(ligne);
    }
    fichier.close();
    return liste;
}

// Code très moche à changer si j'ai envie
// mais ça fontionne BG

void initListOfRecettes(void) {
    system("ls recettes/*.csv > recettes/recettes.txt");
    std::ifstream fichier("recettes/recettes.txt");
    if (!fichier) {
        std::cout << "Erreur: le fichier n'a pas pu être ouvert" << std::endl;
        return;
    }
    std::string ligne;
    std::vector<std::string> liste;
    while (getline(fichier, ligne)) {
        ligne.erase(ligne.size() - 4, ligne.size());
        ligne.erase(0, 9);
        liste.push_back(ligne);
    }
    fichier.close();
    system("echo > recettes/recettes.txt");
    for (size_t i = 0; i < liste.size(); i++) {
        system(("echo " + liste[i] + " >> recettes/recettes.txt").c_str());
    }
    system("sed -i '/^$/d' recettes/recettes.txt");
}