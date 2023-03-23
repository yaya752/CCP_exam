#include <algorithm>
#include "deviant.hpp"
Cite CITE = Cite();
int Individu::compteur = 0;

Cite::Cite() : nb(0)
{
}
Cite::~Cite() {}
int Cite::size()
{
    return nb;
}
void Cite::incrsize()
{
    nb++;
}
void Cite::decrsize()
{
    nb--;
}
Personne::Personne(Cite *CI) : Individu(), nom("inconnu"), type(TYPE::PERSONNE), C(CI)
{
    C->incrsize();
}
Individu::Individu()
{
    compteur++;
    Id = compteur;
}

Personne::Personne(std::string nom1, Cite *CI) : Individu(), nom(nom1), C(CI)
{
    C->incrsize();
}
std::string Personne::getNom() const
{
    return nom;
}
void Personne::setNom(std::string nom1)
{
    nom = nom1;
}
int Individu::getCompteur()
{
    return compteur;
}
void Individu::afficher(std::ostream &os)
{
    os << getCompteur();
}
int Individu::getId() const
{
    return Id;
}
void Personne::afficher(std::ostream &os)
{
    os << nom << " " << getCompteur();
}
void operator<<(std::ostream &os, Individu i)
{
    i.afficher(os);
}
void operator<<(std::ostream &os, Personne i)
{
    i.afficher(os);
}
Individu::Individu(int id) : Id(id)
{
}
const char *IllegalException::what()
{
    return "illegal exception";
}
TYPE Individu::getType() const
{
    throw IllegalException();
}
TYPE Personne::getType() const
{
    return type;
}
Individu::~Individu() {}
Personne::~Personne()
{
    C->decrsize();
}
void Personne::plusdslacite()
{
    C->decrsize();
    C = nullptr;
}
Deviant::Deviant(Personne p) : Individu(p.getId()), nom(p.getNom()), type(TYPE::DEVIANT)
{
}
Deviant::Deviant() {}
Deviant::Deviant(Personne p, std::string obs) : Individu(p.getId()), nom(p.getNom()), Obs(obs), type(TYPE::DEVIANT)
{
}
void Deviant::setObs(std::string obs)
{
    Obs = obs;
}
std::string Deviant::getObs() const
{
    return Obs;
}
bool operator<(const Deviant d1, const Deviant d2)
{

    return d1.getObs() < d2.getObs();
}
TYPE Deviant::getType() const
{
    return type;
}
Covid::Covid() : capacite(0), pointeur(0) {}
Covid::~Covid() {}
Deviant &Covid::top()
{
    return listdev[pointeur - 1];
}
void Covid::pop()
{
}
void Covid::push(Deviant &d)
{
    if (pointeur == capacite)
    {
        int i = 0;
        int j = 0;
        capacite = 1 + capacite * 2;
        Deviant *listdev1 = new Deviant[capacite];
        while (i < pointeur && j == i)
        {
            if (operator<(listdev[i], d))
            {
                listdev1[j] = listdev[i];
                j++;
                i++;
            }
            else
            {
                listdev1[j] = d;
                j++;
            }
        }
        for (i; i < pointeur; i++)
        {
            listdev1[i + 1] = listdev[i];
        }
        delete listdev;
        listdev = listdev1;
    }
    else
    {
        int i = 0;
        while (i < pointeur)
        {
            if (!(operator<(listdev[i], d)))
            {
                
                listdev[i] = d;
                i++;
            }
            else
            {
                
            }
        }
        for (i; i < pointeur; i++)
        {
            listdev1[i + 1] = listdev[i];
        }

    }
}