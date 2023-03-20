#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
// completer la liste suivant vos besoins

enum class TYPE
{
    PERSONNE,
    DEVIANT
};

// Utiliser une des versions de Cite
// #define CITE Cite::getCite()
// extern Cite CITE;

class Personne
{
std::string nom;

public:
    Personne(std::string);
    std::string getNom() const;
    void setNom(std::string);
}

#endif
