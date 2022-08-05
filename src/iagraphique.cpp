#include "../include/IAGraphique.hpp"

IAGraphique::IAGraphique(void) {
    this->m_parametres = std::vector<float>();
    this->m_numberOfParameters = 1;
    std::cout << "Merci d'entrer le nombre de paramètres de votre IA" << std::endl;
}

IAGraphique::IAGraphique(unsigned int nb_parametres) {
    this->m_parametres = std::vector<float>();
    this->m_numberOfParameters = nb_parametres;
}

IAGraphique::~IAGraphique(void) {
    this->m_parametres.clear();
}

void IAGraphique::setNumberOfParameters(unsigned int nb_parametres) {
    this->m_numberOfParameters = nb_parametres;
}

bool IAGraphique::fonction(std::map<X, Y> values) {
    float separateur = 0.0;
    unsigned int counter = 0;
    auto it = values.begin();
    for (int i = 0; i < m_parametres.size(); i++) {
        separateur += pow(it->first, counter) * m_parametres[i];
        counter++;
    }
    if (separateur > it->second) {
        return POSITIVE;
    }
    return NEGATIVE;
}

void IAGraphique::train(std::map<std::map<X, Y>, bool> values) {
    this->m_parametres.clear();
    for (int i = 0; i < this->m_numberOfParameters; i++) {
        this->m_parametres.push_back(0.5);
    }
    for (auto it = values.begin(); it != values.end(); it++) {
        while (fonction(it->first) != it->second) {
            int index = rand() % m_parametres.size();
            if (it->second == POSITIVE) {
                m_parametres[index] += 0.01;
            } else {
                m_parametres[index] -= 0.01;
            }
        }
    }
    for (int i = 0; i < this->m_numberOfParameters; i++) {
        std::cout << m_parametres[i] << " ";
    }
}