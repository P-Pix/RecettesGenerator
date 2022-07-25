#pragma once

#include "Recette.hpp"
#include "Ingredient.hpp"


class GUI {
    private:
        Recette m_RecetteCourante;
        void addIngredient(const char *name, const char *type);
        void addRecette(const Recette *recette, const char *type);
        
    public:
        GUI(void);
        GUI(int argc, char **argv);
        ~GUI(void);
        void init(int argc, char **argv);
};