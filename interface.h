#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QAction>
#include <QIcon>
#include "qgraphe.h"
#include <QMdiArea>
#include <QMessageBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QtGui>

class Interface : public QMainWindow//Classe Interface
{
    Q_OBJECT

private:

    QGraphe *scene;//Attribut Scene
    QGraphicsView *vue;//Attribut Vue

    QAction *actionNouveau;
    QAction *actionSauvegarde;
    QAction *actionExporter;
    QAction *actionOuvrir;
    QAction *actionQuitter;
    QAction *actionNomSommets;
    QAction *actionValeurSommets;
    QAction *actionNomArcs;
    QAction *actionValeurArcs;
    QAction *actionInfosAlgos;

    QMessageBox *erreur;

    QPushButton *supprimer_sommet;//Attribut supprimer_sommet
    QPushButton *supprimer_arc;//Attribut supprimer_arc

    QPushButton *extraire_sgp;//Attribut extraire_sgp
    QPushButton *supprimer_tout;//Attribut supprimer_tout
    QPushButton *mat_info;//Attribut mat_info
    QPushButton *definir_sgp;//Attribut definir_sgp

    QPushButton *centrer;//Attribut centrer
    QPushButton *bouton_selection_simple;//Attribut selection_simple
    QPushButton *bouton_selection_multiple;//Attribut selection_multiple
    QPushButton *bouton_suppression_multiple;//Attribut bouton_supprimer_arcs_ou_sommets

    QPushButton *add_sommets;//Attribut Ajout Sommets
    QPushButton *add_arcs;//Attribut Ajout Arcs
    QComboBox *liste_procedures;//Attribut liste_procedures
    QLabel *procedures;//Attribut procedures

    qreal zoomIN=1.5;//Attribut zoomIN(+)
    qreal zoomOUT=1.0;//Attribut zoomOUT(-)
    char zoomMAX=0;//Attribut zoomMAX

private slots:

    void choix_new();//Fonction Nouveau Fichier A FAIRE
    void choix_open();//Fonction Ouvrir Fichier A FAIRE
    void choix_save();//Fonction Sauvegarde Fichier A FAIRE
    void choix_export();//Fonction Exporter Fichier A FAIRE
    void affiche_noms_sommets();//Fonction Affiche Noms Sommets A FAIRE
    void affiche_valeurs_sommets();//Fonction Affiche Valeurs Sommets A FAIRE
    void affiche_noms_arcs();//Fonction Affiche Noms Arcs A FAIRE
    void affiche_valeurs_arcs();//Fonction Affiche Valeurs Arcs A FAIRE

    void fenetre_infos_algos();//Fonction Affichage Des Infos Pour Les Algos


    void zoom();//Fonction De Zoom +
    void dezoom();//Fonction De Zoom -

    void nomSommetChanged(int);

public:

    Interface(QWidget *parent = 0,Qt::WindowFlags fl = Qt::Window);//Constructeur
    virtual ~Interface();//Destructeur
    void creerMenu();//Fonction Initialisation Du Menu
    void creerAction();//Fonction Initialisation Des Actions
    void creerOutils();//Fonction Initialisation Des Outils
    void fenetre_sommet();//Fonction Affichage De la Fenêtre Information Sommets
    void fenetre_arc();//Fonction Affichage De la Fenêtre Information Arcs
    void fenetre_graphe();//Fonction Affichage De la Fenêtre Information Graphes
    void fenetre_ajout_algo();//Fonction Affichage De la Fenêtre Ajout/Algo
    void fenetre_dessin();//Fonction Fenêtre De Visualisation
    void setNomSommet(int q);
};

#endif // INTERFACE_H
