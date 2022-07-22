#pragma once

#include "Recette.hpp"
#include "Ingredient.hpp"

class GUI {
    private:
        Recette m_Recette;
        void addIngredient(const char *name, const char *type);
        void addRecette(const Recette *recette, const char *type);
        
    public:
};