#ifndef GRAPHE_H
#define GRAPHE_H

#include <string>
#include <vector>
#include <map>
#include "arc.h"

using namespace std;

class Graphe
{

private:
        int _idg;                       	// identifiant
        int _taille;				// taille du graphe
        static int _nbGraphes;			// le nombre total de graphe (vu comme un compteur de _id)
        string _nom;				// nom du graphe
        vector< vector<Arc*> > _Mgraphe;		// le graphe
        vector<Sommet*> _LSommets;		// la liste des sommets avec clé int et objet sommet

public:
        Graphe();//Constructeur par defaut
        Graphe(int idg ,string nom); // Constructeur chargement
        Graphe(const Graphe &g); // Constructeur par copie
        //Graphe(vector<Sommet> &vs,vector<Arc> &va);  //Construit un graphe à partir d’un graphe partiel (extraire un sous graphe partiel)
        //void suppensemble(vector <Sommet> &vs);/supprime un ensemble de sommets avec les arcs qui les lies.



    // Ajouter
        void ajouterSommet(Sommet *s);
        void ajouterArc(int ido, int idd);
        void ajouterArc(string nom, int ida, bool typeReel, double val[2], int ido, int idd);

    // Supprimer
        void suppSommet(int id);	// un seul
        void suppArc(Sommet *orig, Sommet *dest);// un seul
        void suppArc(int ido, int idd);

    // Existance



    //bool memeGraphe(Sommet &s1,Sommet &s2);
    bool existeArc(Sommet &s1, Sommet &s2);
    bool existeArc(int ids1, int ids2);
    vector<Arc> SuccesseursArcs(int id);// Successeurs d'un sommet
    vector<Arc> SuccesseursArcs(Sommet &s);// Successeurs d'un sommet

    // Getter
    vector< vector<int> > getMatrice();
    string getNom();
    int getTaille();
    int getIdg();
    Sommet getSommet(int id);
    Arc* getArc(int ido, int idd);
    static int nbGraphes();
    vector<Sommet *> getLSommets() const;

    //Setter
    void setNom(string nom);
    void setIdg(int idg);
    void setTaille(int taille);
    void setLSommets(vector<Sommet *> LSommets);

    // Marquage
    void marquerSommet(int id);
    void demarquerSommet(int id);

    // visiter ?
    bool visiter(int id);

    ~Graphe();//Destructeur

};

#endif // GRAPHE_H
