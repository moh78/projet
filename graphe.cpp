#include "graphe.h"
#include <iostream>



Graphe::Graphe()
{
    _idg=_nbGraphes;     // identifiant
    _taille=0;		    // taille du graphe		// le nombre total de graphe (vu comme un compteur de _id)
    _nom="NULL";		// nom du graphe

    _nbGraphes++;
}

Graphe::Graphe(int idg, string nom)
{
    _idg=idg;     // identifiant
    _taille=0;		    // taille du graphe		// le nombre total de graphe (vu comme un compteur de _id)
    _nom=nom;		// nom du graphe

    _nbGraphes++;
}

Graphe::Graphe(const Graphe &g)
{
    _idg=g._idg;     // identifiant
    _taille=g._taille;		    // taille du graphe		// le nombre total de graphe (vu comme un compteur de _id)
    _nom=g._nom;		// nom du graphe
    _Mgraphe=g._Mgraphe;		// le graphe
    _LSommets=g._LSommets;		    // la liste des sommets avec clé int et objet sommet

    _nbGraphes++;
}

void Graphe::ajouterSommet(Sommet *s)
{
    if(_taille == 0)
    {
        _Mgraphe.push_back(vector<Arc*>(_taille+1));
    }

    else
    {
        _Mgraphe.push_back(vector<Arc*>(_taille + 1));
        for(int i=0; i<_taille; i++)
        {
            _Mgraphe[i].push_back(NULL);
        }
    }
    _LSommets.push_back(s);
    _taille++;
}

void Graphe::ajouterArc(int ido, int idd)
{
    _Mgraphe[ido][idd]= new Arc(_LSommets[ido], _LSommets[idd]);
}

void Graphe::ajouterArc(string nom, int ida, bool typeReel, double val[2], int ido, int idd)
{
    _Mgraphe[ido][idd]= new Arc(nom, ida, typeReel, val, _LSommets[ido], _LSommets[idd]);
}

void Graphe::suppSommet(int id)
{
    _Mgraphe.erase(_Mgraphe.begin()+id-1);
    for(int i=0; i<_taille-1; i++)
    {
        _Mgraphe[i].erase(_Mgraphe[i].begin()+id-1);
    }
    _LSommets.erase(_LSommets.begin()+id-1);

    for(int j=id; j<_LSommets.size(); j++)
    {
        _LSommets[j]->setIds(j);
    }

    _taille--;
}

void Graphe::suppArc(Sommet *orig, Sommet *dest)
{
    _Mgraphe[orig->getIds()][dest->getIds()] = NULL;
}

void Graphe::suppArc(int ido, int idd)
{
     _Mgraphe[ido][idd] = NULL;
}

bool Graphe::existeArc(Sommet &s1, Sommet &s2)
{
    return _Mgraphe[s1.getIds()][s2.getIds()] != NULL;
}

bool Graphe::existeArc(int ids1, int ids2)
{
    return _Mgraphe[ids1][ids2] != NULL;
}

vector<Arc> Graphe::SuccesseursArcs(int id)
{
    vector<Arc> la;
    for(int i=0; i<_taille; i++)
    {
        if(existeArc(id, i))
        {
            la.push_back(*_Mgraphe[id][i]);
        }
    }
    return la;
}

vector<Arc> Graphe::SuccesseursArcs(Sommet &s)
{
    vector<Arc> la;
    int id = s.getIds();
    for(int i=0; i<_taille; i++)
    {
        if(existeArc(id, i))
        {
            la.push_back(*_Mgraphe[id][i]);
        }
    }
    return la;
}

vector<vector<int> > Graphe::getMatrice()
{
    vector< vector<int> > matrice(_taille);
    for(int i=0; i<_taille; i++)
    {
        for(int j=0; j<_taille; i++)
        {
            if(_Mgraphe[i][j] != NULL)
            {
                matrice[i][j]=1;
            }
            else
            {
                 matrice[i][j]=0;
            }
        }
    }
    return matrice;
}

string Graphe::getNom()
{
    return _nom;
}

int Graphe::getTaille()
{
    return _taille;
}

int Graphe::getIdg()
{
    return _idg;
}

Sommet Graphe::getSommet(int id)
{
    return _LSommets[id];
}

Arc *Graphe::getArc(int ido, int idd)
{
    return _Mgraphe[ido][idd];
}

int Graphe::nbGraphes()
{
    return _nbGraphes;
}

vector<Sommet*> Graphe::getLSommets() const
{
    return _LSommets;
}

void Graphe::setLSommets(vector<Sommet*> LSommets)
{
    _LSommets = LSommets;
}

void Graphe::setNom(string nom)
{
    _nom=nom;
}

void Graphe::setIdg(int idg)
{
    _idg = idg;
}

void Graphe::setTaille(int taille)
{
    _taille = taille;
}

void Graphe::marquerSommet(int id)
{
    _LSommets[id]->setEtat(true);
}

void Graphe::demarquerSommet(int id)
{
    _LSommets[id]->setEtat(false);
}

bool Graphe::visiter(int id)
{
    return _LSommets[id]->getEtat();
}

Graphe::~Graphe()
{
    if(_taille > 0)
    {
        for(int i=0; i<_taille; i++)
        {
            for(int j=0; j<_taille; j++)
            {
                delete _Mgraphe[i][j];
            }
        }

    }

    //delete _Mgraphe;
    _nbGraphes--;
    cout<< "Destructeur Graphe"<<endl;
}

int Graphe::_nbGraphes;
