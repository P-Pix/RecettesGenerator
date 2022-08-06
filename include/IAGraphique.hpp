#pragma once

#include <iostream> 
#include <fstream>
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
        double m_distance;
        std::string m_filename;
        void save(void);

    public:
        IAGraphique(void);
        IAGraphique(unsigned int nb_parametres);
        IAGraphique(unsigned int nb_parametres, std::string filename);
        ~IAGraphique(void);
        void setNumberOfParameters(unsigned int nb_parametres);
        bool fonction(std::map<X, Y> values);
        void train(std::map<std::map<X, Y>, bool> values);
        void setFilename(std::string filename);
        void saveState(std::string filename);
        void loadState(std::string filename);
};