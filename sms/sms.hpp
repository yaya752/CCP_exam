#ifndef __SMS
#define __SMS
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <list>
class Reseau;
class MMS;
class Telephone
{
    std::string numero;
    Reseau *r;
    int nbmess;

public:
    Telephone();
    Telephone(std::string, Reseau *res = 0);
    ~Telephone();

public:
    std::string getNumero() const;
    void setNumero(std::string nouveauNumero);
    Reseau *getReseau() const;
    int getNbMessages() const;
    void setNbMessages();
    void textoter(std::string numeroDest, std::string texte);
    void mmser(std::string,MMS*);
};
class Reseau
{
    Telephone *reseau;
    int pointeur;
    int capacite;

public:
    std::string lister() const;
    void ajouter(std::string);
    Telephone &trouveTel(std::string numero) const;

public:
    Reseau();
    ~Reseau();
};
class MauvaisNumero : public std::exception
{
public:
    virtual const char *what();
};
class Message
{
    std::string expe;
    std::string dest;
    std::string date;
    static int cle;
    int Id;

public:
    virtual ~Message() = 0;
    Message(std::string expe, std::string dest, std::string date);
    Message();
    virtual std::string afficher() const;
    static int getCle();
    int getId();
};
class SMS : public Message
{
    std::string texte;

public:
    SMS(std::string expe, std::string dest, std::string date);
    void setTexte(std::string);
    std::string getTexte() const;
    std::string afficher() const;
};
class Media
{

public:
    Media();
    virtual ~Media();

public:
    virtual std::string afficher() const = 0;
};
class Image : public Media
{

public:
    Image();

public:
    std::string afficher() const;
};
class Video : public Media
{

public:
    Video();

public:
    std::string afficher() const;
};
class Son : public Media
{

public:
    Son();

public:
    std::string afficher() const;
};
class MMS : public SMS
{

    std::list<Media*> joint;
    Telephone * teldest;
    Telephone * telexpe;
public:
    MMS();
    ~MMS();
    MMS(std::string expe, std::string dest, std::string date);
    void joindre(Media *);
    std::string afficher()const override;
    std::string getDe() const;
    std::string getA() const;
    void setDea(Telephone * Dea);
    void setA(Telephone * A);


};
#endif