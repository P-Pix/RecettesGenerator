#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define INGREDIENT_VIANDE_FILE "ingredients/viandes.txt"
#define INGREDIENT_FRUIT_FILE "ingredients/fruits.txt"
#define INGREDIENT_LAITAGE_FILE "ingredients/laitages.txt"
#define INGREDIENT_LEGUMES_FILE "ingredients/legumes.txt"
#define INGREDIENT_FECULENTS_FILE "ingredients/feculents.txt"

class Ingredient {
    private:
        int m_nombreIngredients = 0;
        std::string m_FileName;
        std::string *m_listeIngredients = nullptr;

        // Méthode privée pour lire un fichier txt et remplir les attributs de la classe
        void readFile(void);

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

        // Setter
        void addAnIngredient(const std::string ingredient);

        // Méthode pour afficher les ingrédients
        friend std::ostream &operator<<(std::ostream &os, const Ingredient &ingredient) {
            for (int i = 0; i < ingredient.m_nombreIngredients; i++) {
                os << ingredient.m_listeIngredients[i] << std::endl;
            }
            return os;
        }
};