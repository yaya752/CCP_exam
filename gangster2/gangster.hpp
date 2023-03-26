// NOM    :
// PRENOM :

#ifndef __gangster_hpp__
#define __gangster_hpp__
#include <iostream>
#include<list>
class Personne
{
    std::string Nom;

public:
    Personne(std::string);
    ~Personne();

public:
    std::string getNom() const;
    void setNom(std::string);
    bool equals(const Personne) const;
};
class Gangster : public Personne
{
    int Id;
    int Influence;
    static int compteur;

public:
    Gangster();

public:
    int getId() const;
    int getInfluence() const;
    Personne getPersonne() const;
    void setPersonne(const Personne);
    void setInfluence(const int);
    bool operator<(const Gangster) const;
};

class Chef : public Gangster
{
    Gangster **equipe;
    int taille;
    int pointeur;

public:
    Chef();
    ~Chef();

public:
    void commande(Gangster *);
};
class InconnuException : public std::exception
{
public:
    virtual const char *what();
};
class Famille
{
    Gangster **fam;
    int taille;
    int pointeur;

public:
    Famille();
    ~Famille();

public:
    void ajouter(Gangster*);
    void listePersonnes(std::ostream&) const;
};
bool comparaison(Gangster * g, Gangster * g1);
extern Personne INCONNU;
#endif
