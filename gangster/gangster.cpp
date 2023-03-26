#include "gangster.hpp"

int Gangster::compteur = 1;
const char* InconnuException::what()
{
    return "personnalite inconnue";
}
Personne::Personne(std::string nom1):nom(nom1)
{
}
std::string Personne::getNom() const
{
    return nom;
}   
 
void Personne::setNom(std::string nouveau_nom) 
{
    nom = nouveau_nom;
} 
Personne::Personne():nom{""}
{

} 

Personne::~Personne(){

}

Personne Gangster::getPersonne() const
{
    if (nom == "")
    {
        throw InconnuException();
    }
    else
    {
        return Personne(nom);
    }
}
//Personne INCONNU = Personne("INCONNU");

Gangster::Gangster():Id{compteur},Influence{1}
{
    compteur++;
}

Gangster::~Gangster()
{
}
int Gangster::getId() const
{
    return Id;
}
int Gangster::getInfluence() const
{
    return Influence;
}

Chef::Chef():compteur{0},equipe{nullptr}
{
}
Chef::~Chef()
{
    delete []  equipe ;
}
void Chef::commande(Gangster * soldat)
{
    if (compteur == 0)
    {
        equipe = new Gangster*[100];
        equipe[0] = soldat;
        compteur++;
        Influence = 10 + soldat->Influence;
        
    }
    else
    {
        equipe[compteur] = soldat;
        compteur++;
        Influence+=soldat->Influence;
    }
}
void Gangster::setPersonne(const Personne individu)
{
    setNom(individu.nom);

}
bool Personne::equals(Personne individu) const
{
    return individu.nom == nom;
    
}
bool Gangster::operator<(const Gangster individu1) const
{
    return Influence <= individu1.Influence;
}
Famille::Famille():capacite{1},pointeur{0},famille{nullptr}
{}
Famille::~Famille(){
    for(int i=0; i<pointeur; i++)
    {
        delete famille[i];
    }
    delete [] famille;
}
void Famille::ajouter(Gangster * soldat)
{
    if (pointeur == capacite-1) { // Si le tableau est plein
        // Double la taille du tableau
        capacite *= 2;
        Gangster ** nouvelleFamille = new Gangster *[capacite];
        // Copie les pointeurs existants dans le nouveau tableau
        for (int i = 0; i < pointeur; i++) {
            nouvelleFamille[i] = famille[i];
        }
        // Libère l'ancien tableau
        delete[] famille;
        famille = nouvelleFamille;
    }
    // Ajoute le nouveau gangster à la fin du tableau
    famille[pointeur] = soldat;
    pointeur++;
}

void Famille::listePersonnes(std::ostream & os) const
{
    std::vector<std::string> v;
    for(int i = 0; i<pointeur-1; i++)
    {
        if (famille[i]->getNom() != "")
        {
            v.push_back(famille[i]->getNom());
        }
    }
    std::sort(v.begin(),v.end());
    std::copy (v.begin(), v.end()-1, std::ostream_iterator<std::string> (os, ", "));
    std::copy (v.end()-1, v.end(), std::ostream_iterator<std::string> (os, ""));
}
void operator<<(std::ostream & os, const Famille &f) 
{
    std::vector<std::string> v;
    std::sort(v.begin(),v.end());
    for(int i = 0; i<f.pointeur-1; i++)
    {
        if (f.famille[i]->getNom() != "")
        {
            v.push_back(f.famille[i]->getNom());
        }
    }
    std::sort(v.begin(),v.end());
    std::copy (v.begin(), v.end()-1, std::ostream_iterator<std::string> (os, ", "));
    std::copy (v.end()-1, v.end(), std::ostream_iterator<std::string> (os, ""));
}
bool FoncteurInf::operator()(Gangster * g1, Gangster * g2) const
{
    return  (g1->getInfluence() <= g2->getInfluence());
}
void Famille::listeMembres(std::ostream & os) const
{
    std::vector<Gangster *> v;
    std::vector<int> v1;
    for(int i = 0; i<pointeur; i++)
    {
        v.push_back(famille[i]);
    }
    std::sort(v.begin(),v.end(),FoncteurInf());
    for(int i = 0; i<pointeur; i++)
    {
        v1.push_back(v[pointeur-1-i]->getId());
    }
    std::copy (v1.begin(), v1.end()-1, std::ostream_iterator<int> (os, " "));
    std::copy (v1.end()-1, v1.end(), std::ostream_iterator<int> (os, ""));
}