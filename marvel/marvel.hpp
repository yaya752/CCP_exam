#ifndef marvel__hpp
#define marvel__hpp
#include <iostream>

class Personne
{
public:
    enum Genre
    {
        HOMME,
        FEMME,
        INDETERMINE
    };
    static Personne INCONNU;

private:
    std::string nom;
    std::string prenom;
    Genre genre;

public:
    Personne();
    ~Personne();
    Personne(std::string nouveauPrenom, std::string nouveauNom, Genre nouveauGenre = Personne::INDETERMINE);

public:
    std::string getNom() const;
    std::string getPrenom() const;
    Personne::Genre getGenre() const;
    void setNom(const std::string nouveauNom);
    void setPrenom(const std::string nouveauPrenom);
    void setGenre(const Genre nouveauGenre);
    void afficher(std::ostream &os);
};
class AnonymeException : public std::exception
{
public:
    const char *what();
};
class Capacite
{
public:
    std::string nomCapa;
    int niveau;

public:
    virtual void utiliser(std::ostream &os) const;
    Capacite(std::string nomCapa, int niveau);
    Capacite();
    virtual Capacite *clone() const;
    virtual ~Capacite();
    std::string getNom() const;
};
class Super
{
private:
    std::string nomScene;
    Personne Identite;
    int Niveau;
    bool anonimat;
    int pointeur;
    int nombre_capa;
    Capacite **listCapa;

public:
    Super(std::string nom, Personne Id, int Niveau = 0, bool anonimat = true);
    void ajouter(Capacite *capa);
    ~Super();
    Super(const Super &);

public:
    std::string getNom() const;
    bool estAnonyme() const;
    void enregistrer();
    Personne getIdentite() const;
    void setIdentite(const Personne nouvelleId);
    int getNiveau() const;
    void setNom(std::string nom);
};

class Materiel : public Capacite
{
public:
    void actionner(std::ostream &os) const;
    Materiel(std::string nomCapa, int niveau);
    void utiliser(std::ostream &os) const;
    virtual Materiel *clone() const;
    Materiel();
};
class Physique : public Capacite
{
public:
    void exercer(std::ostream &os) const;
    Physique(std::string nomCapa, int niveau);
    void utiliser(std::ostream &os) const;
};
class Psychique : public Capacite
{
public:
    void penser(std::ostream &os) const;
    Psychique(std::string nomCapa, int niveau);
    void utiliser(std::ostream &os) const;
};
class Equipe
{
    std::string nomEquipe;
    int pointeur;
    int nombre;
    int niveau;
    Super **equipe;

    

public:
    Equipe(std::string);
    void ajouter(Super * super);
    int getNombre() const;
    int getNiveau() const;

};
bool operator==(Personne p1, Personne p2);
void operator<<(std::ostream &os, Personne p1);
#endif
