#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
// completer la liste suivant vos besoins

enum class TYPE
{
    PERSONNE,
    DEVIANT
};
class Cite
{
    int nb;

public:
    Cite();
    ~Cite();
    int size();
    void incrsize();
    void decrsize();
};
class Individu
{
    static int compteur;
    int Id;

public:
    Individu(std::string);
    Individu();
    Individu(int);
    virtual ~Individu();
    static int getCompteur();
    int getId() const;
    virtual void afficher(std::ostream &);
    virtual TYPE getType() const;
};
extern Cite CITE;
class Personne : public Individu
{
    std::string nom;
    TYPE type;
    Cite *C;

public:
    Personne(Cite *Ci = &CITE);
    ~Personne();
    Personne(std::string, Cite *CI = &CITE);
    std::string getNom() const;
    void setNom(std::string);
    void afficher(std::ostream &);
    TYPE getType() const;
    void plusdslacite();
};
class IllegalException : public std::exception
{
public:
    virtual const char *what();
};
class Deviant : public Individu
{
    std::string nom;
    std::string Obs;
    TYPE type;

public:
    Deviant();
    Deviant(Personne);
    Deviant(Personne, std::string);
    void setObs(std::string);
    std::string getObs() const;

    TYPE getType() const;
};
bool operator<(const Deviant, const Deviant);
class Covid
{
    Deviant *listdev;
    int capacite;
    int pointeur;

public:
    Covid();
    ~Covid();
    Deviant &top();
    void pop();
    void push(Deviant &d);
};
void operator<<(std::ostream &, Individu);
void operator<<(std::ostream &, Personne);
#endif
