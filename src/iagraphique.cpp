#include "../include/IAGraphique.hpp"

IAGraphique::IAGraphique(void) {
    this->m_filename = "";
    this->m_parametres = std::vector<float>();
    this->m_numberOfParameters = 1;
    this->m_distance = 0;
    std::cout << "Merci d'entrer le nombre de paramètres de votre IA" << std::endl;
}

IAGraphique::IAGraphique(unsigned int nb_parametres) {
    this->m_filename = "";
    this->m_parametres = std::vector<float>();
    this->m_numberOfParameters = nb_parametres;
    this->m_distance = 0;
}

IAGraphique::IAGraphique(unsigned int nb_parametres, std::string filename) {
    this->m_filename = filename;
    this->m_parametres = std::vector<float>();
    this->m_numberOfParameters = nb_parametres;
    this->m_distance = 0;
}

IAGraphique::~IAGraphique(void) {
    this->m_parametres.clear();
}

void IAGraphique::setFilename(std::string filename) {
    this->m_filename = filename;
}

void IAGraphique::saveState(std::string filename) {
    this->m_filename = filename;
    this->save();
}

void IAGraphique::loadState(std::string filename) {
    this->m_filename = filename;
    std::ifstream file(this->m_filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            this->m_parametres.push_back(std::stof(line));
        }
        file.close();
        this->m_numberOfParameters = this->m_parametres.size();
    } else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
}

void IAGraphique::setNumberOfParameters(unsigned int nb_parametres) {
    this->m_numberOfParameters = nb_parametres;
}

bool IAGraphique::fonction(std::map<X, Y> values) {
    float separateur = 0.0;
    unsigned int counter = 0;
    auto it = values.begin();
    for (size_t i = 0; i < m_parametres.size(); i++) {
        separateur += pow(it->first, counter) * m_parametres[i];
        counter++;
    }
    this->m_distance = sqrt(pow(separateur, 2) + pow(it->second, 2));
    if (separateur > it->second) {
        return POSITIVE;
    }
    return NEGATIVE;
}

void IAGraphique::train(std::map<std::map<X, Y>, bool> values) {
    this->m_parametres.clear();
    double lastDistance = 0;
    double lastUpdate = 0;
    unsigned int index = 0;
    for (size_t i = 0; i < this->m_numberOfParameters; i++) {
        this->m_parametres.push_back(0.5);
    }
    for (auto it = values.begin(); it != values.end(); it++) {
        while (fonction(it->first) != it->second) {
            if (lastUpdate == 0) {
                if (it->second == POSITIVE) {
                    m_parametres[index] += 0.01;
                    lastUpdate = 0.01;
                } else {
                    m_parametres[index] -= 0.01;
                    lastUpdate = -0.01;
                }
            } else if (lastUpdate > 0) {
                std::cout << "lastUpdate > 0" << std::endl;
                if (lastDistance < this->m_distance) {
                    std::cout << "lastDistance < this->m_distance" << std::endl;
                    m_parametres[index] += 0.01;
                    lastUpdate = 0.01;
                } else {
                    std::cout << "lastDistance >= this->m_distance" << std::endl;
                    m_parametres[index] -= 0.01;
                    lastUpdate = -0.01;
                    index = (index + 1) % this->m_numberOfParameters;
                }
            } else if (lastUpdate < 0) {
                std::cout << "lastUpdate < 0" << std::endl;
                if (lastDistance < this->m_distance) {
                    std::cout << "lastDistance < this->m_distance" << std::endl;
                    m_parametres[index] -= 0.01;
                    lastUpdate = -0.01;
                } else {
                    std::cout << "lastDistance >= this->m_distance" << std::endl;
                    m_parametres[index] += 0.01;
                    lastUpdate = 0.01;
                    index = (index + 1) % this->m_numberOfParameters;
                }
            } else {
                std::cout << "Erreur" << std::endl;
            }

            std::cout << "LastDistance: " << lastDistance << std::endl;
            std::cout << "Distance : " << this->m_distance << std::endl;
            std::cout << "Paramètre " << index << " : " << m_parametres[index] << std::endl;
            for (size_t i = 0; i < this->m_parametres.size(); i++) {
                std::cout << this->m_parametres[i] << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;

            lastDistance = this->m_distance;
        }
        lastDistance = 0;
        lastUpdate = 0;
    }
    for (size_t i = 0; i < this->m_numberOfParameters; i++) {
        std::cout << m_parametres[i] << " ";
    }
    this->save();
}

void IAGraphique::save(void) {
    if (this->m_filename.size() > 0) {
        std::ofstream file(this->m_filename);
        for (size_t i = 0; i < this->m_numberOfParameters; i++) {
            file << m_parametres[i] << std::endl;
        }
        file.close();
    } else {
        std::cout << "Merci de spécifier un nom de fichier" << std::endl;
    }
}