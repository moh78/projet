#include "arc.h"
#include <iostream>

Arc::Arc()
{
    _nom="NULL";
    _ida=nbArc();
    _typeReel=NULL;
    _val[0]=0.0;
    _val[1]=0.0;
    _etat=NULL;
    _color[0]=0;
    _color[1]=0;
    _color[2]=0;
    _origine=NULL;
    _destination=NULL;

    _nbArc++;
}

Arc::Arc(Sommet *orig, Sommet *dest)
{
     _nom="NULL";
     _ida=nbArc();
     _typeReel=NULL;
     _val[0]=0.0;
     _val[1]=0.0;
     _etat=NULL;
     _color[0]=0;
     _color[1]=0;
     _color[2]=0;
     _origine=orig;
     _destination=dest;

     _nbArc++;
}

Arc::Arc(string nom, int ida, bool typeReel, double val[2], Sommet *orig, Sommet *dest)
{
    _nom=nom;
    _ida=ida;
    _typeReel=typeReel;
    _val[0]=val[0];
    _val[1]=val[1];
    _etat=NULL;
    _color[0]=0;
    _color[1]=0;
    _color[2]=0;
    _origine=orig;
    _destination=dest;

    _nbArc++;
}

Arc::Arc(Arc *a)
{
    _nom=a->_nom;
    _ida=a->_ida;
    _typeReel=a->_typeReel;
    _val[0]=a->_val[0];
    _val[1]=a->_val[1];
    _etat=a->_etat;
    _color[0]=a->_color[0];
    _color[1]=a->_color[1];
    _color[2]=a->_color[2];
    _origine=a->_origine;
    _destination=a->_destination;

    _nbArc++;
}

string Arc::getNom()
{
    return _nom;
}

int Arc::getIda()
{
    return _ida;
}

bool Arc::get_typeReel()
{
    return _typeReel;
}

double Arc::getVal1()
{
    return _val[0];
}

double Arc::getVal2()
{
    return _val[1];
}

bool Arc::getEtat()
{
    return _etat;
}

int Arc::getColorR()
{
    return _color[0];
}

int Arc::getColorG()
{
    return _color[1];
}

int Arc::getColorB()
{
    return _color[2];
}

Sommet *Arc::getOrigine()
{
    return _origine;
}
Sommet *Arc::getDestination()
{
    return _destination;
}

void Arc::setNom(string nom)
{
    _nom=nom;
}

void Arc::setIda(int ida)
{
    _ida = ida;
}

void Arc::setTypeReel(bool typeReel)
{
    _typeReel=typeReel;
}

void Arc::setVal1(double val)
{
    _val[0]=val;
}

void Arc::setVal2(double val)
{
    _val[1]=val;
}

void Arc::setEtat(bool etat)
{
    _etat=etat;
}

void Arc::setColorR(int colorR)
{
    _color[0]=colorR;
}

void Arc::setColorG(int colorG)
{
    _color[1]=colorG;
}

void Arc::setColorB(int colorB)
{
    _color[2]=colorB;
}

void Arc::setOrigine(Sommet *orig)
{
    _origine=orig;
}
void Arc::setDestination(Sommet *dest)
{
    _destination=dest;
}

int Arc::nbArc()
{
    return _nbArc;
}

Arc::~Arc()
{
    cout<<"\nDestructeur Arc "<<endl;
    _nbArc--;
}

int Arc::_nbArc;//Variable statique
