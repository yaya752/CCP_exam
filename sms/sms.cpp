#include "sms.hpp"
int Message::cle = 0;
Telephone::Telephone() : numero(""),r(nullptr),nbmess(0)
{
}
Telephone::Telephone(std::string nom, Reseau *res) : numero(nom), r(res), nbmess(0)
{
}
Telephone::~Telephone()
{
}
std::string Telephone::getNumero() const
{
    return numero;
}
Reseau *Telephone::getReseau() const
{
    return r;
}
void Telephone::setNumero(std::string nouveauNumero)
{
    numero = nouveauNumero;
}
Reseau::Reseau() : reseau(nullptr), pointeur(0), capacite(10)
{
}
Reseau::~Reseau()
{
    delete[] reseau;
}
std::string Reseau::lister() const
{
    if (reseau != nullptr)
    {
        std::ostringstream ss;
        std::vector<std::string> res;
        for (int i = 0; i < pointeur; i++)
        {
            res.push_back(reseau[i].getNumero());
        }
        std::sort(res.begin(), res.end());
        std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(ss, "\n"));
        return ss.str();
    }
    return "";
}
void Reseau::ajouter(std::string numero)
{
    Telephone  newTel =Telephone(numero, this);
    if (pointeur == 0)
    {
        reseau = new Telephone [capacite];
    }
    else
    {
        if (pointeur == capacite)
        {
            capacite *= 2;
            Telephone *reseauG = new Telephone [capacite];
            for (int i = 0; i < pointeur; i++)
            {
                reseauG[i] = reseau[i];
            }
            delete reseau;
            reseau = reseauG;
        }
    }
    reseau[pointeur] = newTel;
    pointeur++;
}
Telephone& Reseau::trouveTel(std::string numero) const
{
    for (int i = 0; i < pointeur; i++)
    {
        if (!(reseau[i].getNumero().compare(numero)))
        {
            return reseau[i];
        }
    }
    throw MauvaisNumero();
}
const char *MauvaisNumero::what()
{
    return "mauvais numero";
}
Message::Message()
{
}
Message::Message(std::string expe, std::string dest, std::string date) : expe(expe), dest(dest), date(date)
{
    Id = cle;
    cle++;
}
Message::~Message()
{
}
SMS::SMS(std::string expe, std::string dest, std::string date) : Message(expe, dest, date), texte("")
{
}
void SMS::setTexte(std::string newTexte)
{
    if (newTexte.length() <= 160)
    {
        texte = newTexte;
    }
    else
    {
        throw std::invalid_argument("message trop grand");
    }
}
std::string SMS::getTexte() const
{
    return texte;
}
int Message::getCle()
{
    return cle;
}
int Message::getId()
{
    return Id;
}
std::string Message::afficher() const
{
    return "";
}
std::string SMS::afficher() const
{
    return getTexte();
}
int Telephone::getNbMessages() const
{
    return nbmess;
}
void Telephone::setNbMessages()
{
    nbmess++;
}
void Telephone::textoter(std::string numeroDest, std::string texte)
{
    nbmess++;
    try
    {
       Telephone * a = &r->trouveTel(numeroDest);
        a->setNbMessages(); 
    }
    catch(const MauvaisNumero &)
    {
    }
    
    
}
Media::Media(){}
Media::~Media(){}
Video::Video(){}
Son::Son(){}
Image::Image(){}
std::string Video::afficher() const
{
    return "[[video]]";
}
std::string Son::afficher() const
{
    return "[[son]]";
}
std::string Image::afficher() const
{
    return "[[image]]";
}
MMS::MMS(std::string expe, std::string dest, std::string date):SMS(expe,dest,date)
{
}
void MMS::joindre(Media* m)
{
    joint.push_back(m);
}
std::string MMS::afficher() const
{
    std::string retour = getTexte();
    for (Media *m : joint)
    {
        retour += (*m).afficher();
    }
    return retour;
}
MMS::~MMS()
{
    for (Media *m : joint)
    {
        delete m;
    }
}
void Telephone::mmser(std::string dest,MMS * m)
{
    m->setDea(this);
    nbmess++;
    Telephone * a  = & r->trouveTel(dest);
    a->setNbMessages();
    m->setA(a);
}
std::string MMS::getDe() const
{
    return telexpe->getNumero();
}
std::string MMS::getA() const
{
    return teldest->getNumero();
}
void MMS::setDea(Telephone * Dea)
{
    telexpe = Dea;
}
void MMS::setA(Telephone * A)
{
    teldest = A;
}
MMS::MMS():SMS("","","")
{}