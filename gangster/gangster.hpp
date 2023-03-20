// NOM    : Khiara
// PRENOM : Yassine
#ifndef __gangster_hpp__
#define __gangster_hpp__7
#include <stdexcept>
#include <sstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
class Personne{
    public:
        std::string nom;
    public:
        Personne(std::string nom);
        Personne();
        ~Personne();
    public:
        std::string getNom() const;
        void setNom(std::string nouveau_nom);
        bool equals(Personne individu) const;
        
};
class InconnuException : public std::exception
{  
    public:
        virtual const char *  what();

};
class Gangster : public Personne{
    public:
        int Id;
        static int compteur;
        int Influence;
    public :
        Gangster();
        virtual ~Gangster();
    public:
        int getId() const;
        int getInfluence() const ;
        Personne getPersonne() const;
        void setPersonne(const Personne individu);
        bool operator<(const Gangster individu1) const;
};

class Chef : public  Gangster{
    int compteur;
    Gangster ** equipe;
    public:
        Chef();
        virtual ~Chef();
    public:
        void commande(Gangster * soldat);
};
class Famille {
    public:
        int capacite;
        int pointeur;
        Gangster ** famille;
    public:
        Famille();
        virtual ~Famille();
    public:
        void ajouter(Gangster * soldat);
        void listePersonnes(std::ostream & ss) const;
        void listeMembres(std::ostream & os)const ;
        
};
class FoncteurInf{
    public:
        bool operator()(Gangster * g1, Gangster * g2) const;
};
void operator<<(std::ostream & os,const Famille &f);
const Personne INCONNU = Personne{"INCONNU"};
#endif
