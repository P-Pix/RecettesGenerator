#pragma once

#include <iostream> 
#include <vector>
#include <math.h>
#include <map>
#include <random>

#define POSITIVE true
#define NEGATIVE false
#define X float
#define Y float

class IAGraphique {
    private:
        std::vector<float> m_parametres;
        unsigned int m_numberOfParameters;

    public:
        IAGraphique(void);
        IAGraphique(unsigned int nb_parametres);
        ~IAGraphique(void);
        void setNumberOfParameters(unsigned int nb_parametres);
        bool fonction(std::map<X, Y> values);
        void train(std::map<std::map<X, Y>, bool> values);
};