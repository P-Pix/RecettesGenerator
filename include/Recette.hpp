#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COLUMN 3

class Recette {
    private: 
        int m_nombreIngredients = 0;
        int *m_listeQuantites = nullptr;
        std::string *m_listeIngredients = nullptr;
        bool *m_listeOptionnels = nullptr;

        // Méthode privée pour lire un fichier csv et remplir les attributs de la classe
        void readFile(const std::string file);
    
    public:
        // Constructeur par défaut
        Recette(void);
        // Constructeur par une adresse de fichier csv
        Recette(const std::string file);
        // Constructeur par une adresse de fichier csv
        Recette(const char *file);

        // Destructeur
        ~Recette(void);

        // Getter
        int getNombreIngredients(void) const;

        int getQuantite(int index) const;

        std::string getIngredient(int index) const;
        
        bool getOptionnel(int index) const;

        friend std::ostream &operator<<(std::ostream &os, const Recette &recette);
};

std::vector<std::string> getListOfRecettes(void);

void initListOfRecettes(void);