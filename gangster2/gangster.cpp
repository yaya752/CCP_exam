#include "gangster.hpp"
// Personne
Personne INCONNU = Personne("INCONNU");
Personne::Personne(std::string nom) : Nom(nom)
{
}
Personne::~Personne()
{
}
std::string Personne::getNom() const
{
    return Nom;
}
void Personne::setNom(std::string n)
{
    Nom = n;
}
bool Personne::equals(Personne p) const
{
    return (p.getNom() == Nom);
}
// Gangster
int Gangster::compteur = 1;
Gangster::Gangster() : Personne("INCONNU"), Id(compteur), Influence(1)
{
    compteur++;
}
int Gangster::getId() const
{
    return Id;
}
int Gangster::getInfluence() const
{
    return Influence;
}
void Gangster::setInfluence(const int a)
{
    Influence = a;
}
Personne Gangster::getPersonne() const
{
    if (getNom() != "INCONNU")
    {
        return Personne(getNom());
    }
    else
    {
        throw InconnuException();
    }
}
void Gangster::setPersonne(const Personne p)
{
    setNom(p.getNom());
}
bool Gangster::operator<(const Gangster g) const
{
    return (Influence <= g.getInfluence());
}

bool comparaison(Gangster *g, Gangster *g1)
{
    return (g->getInfluence() <= g1->getInfluence());
}
// Chef

Chef::Chef() : Gangster(), equipe(nullptr), taille(0), pointeur(0)
{
}
Chef::~Chef()
{
    delete[] equipe;
}
void Chef::commande(Gangster *g)
{
    if (equipe == nullptr)
    {
        taille = 1;
        setInfluence(10);
        equipe = new Gangster *[taille];
    }
    else
    {
        if (pointeur == taille)
        {
            taille *= 2;
            Gangster **newEquipe = new Gangster *[taille];
            for (int i = 0; i < pointeur; i++)
            {
                newEquipe[i] = equipe[i];
            }
            delete[] equipe;
            equipe = newEquipe;
        }
    }
    setInfluence(g->getInfluence() + getInfluence());
    equipe[pointeur] = g;
    pointeur++;
}

// Exception
const char *InconnuException::what()
{
    return "personnalite inconnue";
}
// Famille
Famille::Famille() : fam(nullptr), taille(0), pointeur(0)
{
}
Famille::~Famille()
{
    for (int i = 0; i < pointeur; i++)
    {
        delete fam[i];
    }
    delete[] fam;
}
void Famille::ajouter(Gangster *g)
{
    if (fam == nullptr)
    {
        taille = 1;
        fam = new Gangster *[taille];
    }
    else
    {
        if (pointeur == taille)
        {
            taille *= 2;
            Gangster **newEquipe = new Gangster *[taille];
            for (int i = 0; i < pointeur; i++)
            {
                newEquipe[i] = fam[i];
            }
            delete[] fam;
            fam = newEquipe;
        }
    }
    fam[pointeur] = g;
    pointeur++;
}
void Famille::listePersonnes(std::ostream &os) const
{
    int i = 0;
    std::list<Gangster *> liste;
    for (int i = 0; i < pointeur; i++)
    {
        liste.push_back(fam[i]);
    }
    liste.sort(comparaison);
    for (Gangster *g : liste)
    {
        if ((g->getNom() != "INCONNU") && (i < pointeur - 1))
        {
            os << g->getPersonne().getNom() << ", ";
        }
        else if ((g->getNom() != "INCONNU") && (i = pointeur -1))
        {
            os << g->getPersonne().getNom();
        }
        i++;
    }
}