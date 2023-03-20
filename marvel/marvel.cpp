#include "marvel.hpp"
Personne Personne::INCONNU;
Personne::Personne() : nom{"Inconnu"}, prenom{"Inconnu"}, genre{Genre::INDETERMINE}
{
}
Personne::Personne(std::string nouveauPrenom, std::string nouveauNom, Genre nouveauGenre) : nom{nouveauNom}, prenom{nouveauPrenom}, genre{nouveauGenre}
{
}
Personne::~Personne()
{
}
std::string Personne::getNom() const
{
    return nom;
}
std::string Personne::getPrenom() const
{
    return prenom;
}
Personne::Genre Personne::getGenre() const
{
    return genre;
}
void Personne::setNom(const std::string nouveauNom)
{
    nom = nouveauNom;
}
void Personne::setPrenom(const std::string nouveauPrenom)
{
    prenom = nouveauPrenom;
}
void Personne::setGenre(const Genre nouveauGenre)
{
    genre = nouveauGenre;
}
void Personne::afficher(std::ostream &os)
{
    std::string genreStr;
    if (genre == Personne::FEMME)
    {
        genreStr = "FEMME";
    }
    else if (genre == Personne::HOMME)
    {
        genreStr = "HOMME";
    }
    else
    {
        genreStr = "INDETERMINE";
    }
    os << prenom << " " << nom << " "
       << "[" << genreStr << "]";
}
bool operator==(Personne p1, Personne p2)
{
    return !((p1.getNom() != p2.getNom()) || (p1.getPrenom() != p2.getPrenom()) || (p1.getGenre() != p2.getGenre()));
}
void operator<<(std::ostream &os, Personne p1)
{
    p1.afficher(os);
}
Super::Super(std::string nom, Personne Id, int Niveau, bool anonimat) : nomScene(nom), Identite(Id), Niveau(Niveau), anonimat(anonimat), listCapa(nullptr)
{
}
Super::~Super()
{
    delete[] listCapa;
}
std::string Super::getNom() const
{
    return nomScene;
}
bool Super::estAnonyme() const
{
    return anonimat;
}
void Super::enregistrer()
{
    anonimat = false;
}
Personne Super::getIdentite() const
{
    if (anonimat)
    {
        throw AnonymeException();
    }
    else
    {
        return Identite;
    }
}
void Super::setIdentite(const Personne nouvelleId)
{
    anonimat = true;
    Identite = nouvelleId;
}
const char *AnonymeException::what()
{
    return "Identite Inconnu";
}
void Materiel::actionner(std::ostream &os) const
{

    os << nomCapa << " [" << niveau << "] en action";
}
Capacite::Capacite(std::string nomCapa, int niveau) : nomCapa(nomCapa), niveau{niveau}
{
}
Materiel::Materiel(std::string nomCapa, int niveau) : Capacite{nomCapa, niveau}
{
}
void Capacite::utiliser(std::ostream &os) const
{
    os << nomCapa << " [" << niveau << "]";
}
Physique::Physique(std::string nomCapa, int niveau) : Capacite{nomCapa, niveau}
{
}
void Physique::exercer(std::ostream &os) const
{
    os << nomCapa << " [" << niveau << "]";
}
Psychique::Psychique(std::string nomCapa, int niveau) : Capacite{nomCapa, niveau}
{
}
void Psychique::penser(std::ostream &os) const
{
    os << nomCapa << " [" << niveau << "]";
}

void Materiel::utiliser(std::ostream &os) const
{
    actionner(os);
}
void Physique::utiliser(std::ostream &os) const
{
    exercer(os);
}
void Psychique::utiliser(std::ostream &os) const
{
    penser(os);
}
Capacite::~Capacite()
{
}
Capacite::Capacite() : nomCapa(""), niveau(0)
{
}
void Super::ajouter(Capacite *capa)
{
    if (listCapa == nullptr)
    {
        pointeur = 0;
        nombre_capa = 4;
        listCapa = new Capacite *[nombre_capa];
    }
    else
    {
        if (pointeur == nombre_capa)
        {
            nombre_capa *= 2;
            Capacite **listCapa1 = new Capacite *[nombre_capa];
            for (int i = 0; i < pointeur; i++)
            {
                listCapa1[i] = listCapa[i];
            }
            delete[] listCapa;
            listCapa = listCapa1;
        }
    }
    listCapa[pointeur] = capa;
    pointeur++;
    Niveau += capa->niveau;
}
int Super::getNiveau() const
{
    return Niveau;
}
Super::Super(const Super &S1) : nomScene(S1.nomScene), Identite(S1.Identite), Niveau(S1.Niveau), anonimat(S1.anonimat), pointeur(S1.pointeur), nombre_capa(S1.nombre_capa)
{
    listCapa = new Capacite *[nombre_capa];
    for (int i = 0; i < pointeur; i++)
    {
        listCapa[i] = S1.listCapa[i];
    }
}
Capacite *Capacite::clone() const
{
    Capacite *c1 = new Capacite();
    c1->niveau = niveau;
    c1->nomCapa = nomCapa;
    return c1;
}
Materiel *Materiel::clone() const
{
    Materiel *c1 = new Materiel();
    c1->niveau = niveau;
    c1->nomCapa = nomCapa;
    return c1;
}
std::string Capacite::getNom() const
{
    return nomCapa;
}
Materiel::Materiel()
{}
void Super::setNom(std::string nom)
{
    nomScene = nom;
}
Equipe::Equipe(std::string nom):nomEquipe(nom), pointeur(0), nombre(0),niveau(0), equipe(nullptr)
{
}
void Equipe::ajouter(Super * super)
{
    if (equipe == nullptr)
    {
        pointeur = 0;
        nombre = 4;
        equipe = new Super *[nombre];
    }
    else
    {
        if (pointeur == nombre)
        {
            nombre *= 2;
            Super **equipe1 = new Super *[nombre];
            for (int i = 0; i < pointeur; i++)
            {
                equipe1[i] = equipe[i];
            }
            delete[] equipe;
            equipe = equipe1;
        }
    }
    equipe[pointeur] = super;
    pointeur++;
    niveau += super->getNiveau();
}
int Equipe::getNombre() const 
{
    return pointeur;
}
int Equipe::getNiveau() const 
{
    return niveau;
}