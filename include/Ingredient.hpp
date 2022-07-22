#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Ingredient {
    private:
        int m_nombreIngredients = 0;
        std::string *m_listeIngredients = nullptr;

        // Méthode privée pour lire un fichier txt et remplir les attributs de la classe
        void readFile(const std::string file);

    public:
        // Constructeur par défaut
        Ingredient(void);
        // Constructeur par une adresse de fichier txt
        Ingredient(const std::string file);
        // Constructeur par une adresse de fichier txt
        Ingredient(const char *file);
        // Destructeur
        ~Ingredient(void);

        // Getter
        int getNombreIngredients(void) const;
        std::string getIngredient(int index) const;

        // Méthode pour afficher les ingrédients
        void print(void) const;
        //friend std::ostream &operator<<(std::ostream &os, const Ingredient &ingredient);
};