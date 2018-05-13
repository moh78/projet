#include "interface.h"

Interface::Interface(QWidget *parent, Qt::WindowFlags fl): QMainWindow(parent,fl)//Constructeur
{
    creerAction();//Fonction Init Action
    creerMenu();//Fonction Init Menu
    creerOutils();//Fonction Init Outils

    fenetre_dessin();//Fonction Fenetre Dessin
    fenetre_sommet();//Fonction Fenetre Sommet
    fenetre_arc();//Fonction Fenetre Arc
    fenetre_graphe();//Fonction Fenetre Graphe
    fenetre_ajout_algo();//Fonction Fenetre Algo

    setWindowTitle("Manipulation De Graphes Orientés Et De Sous Graphe Partiels");//Titre De La Fenêtre
    setMinimumSize(QSize(900,600));//Taille Minimum
    showMaximized();//Plein Ecran

    QObject::connect(this->bouton_selection_simple, SIGNAL(released()), scene, SLOT(deplacer()));
    QObject::connect(this->add_arcs, SIGNAL(released()), scene, SLOT(arc_ajouter()));
    QObject::connect(this->bouton_suppression_multiple, SIGNAL(released()), scene, SLOT(supprimer()));
    QObject::connect(this->add_sommets, SIGNAL(released()), scene, SLOT(sommet_ajouter()));
    QObject::connect(scene->nom_sommet_val, SIGNAL(textChanged(QString)),scene, SLOT(setNomSommet(QString)));
    QObject::connect(supprimer_sommet, SIGNAL(released()),scene, SLOT(supprimerqsommet(QSommet*)));
   // QObject::connect(centrer, SIGNAL(triggered()), this, SLOT(nouveauFichier()));

    vue->setMouseTracking(true);
    vue->setRenderHints(QPainter::Antialiasing);
}

void Interface::creerAction()
{
    actionNouveau = new QAction(QIcon("../Version3/images/new.png"),"&Nouveau",this);
    actionOuvrir = new QAction(QIcon("../Version3/images/open.png"),"&Ouvrir",this);
    actionSauvegarde = new QAction(QIcon("../Version3/images/save.png"),"&Sauvegarder",this);
    actionExporter = new QAction(QIcon("../Version3/images/export.png"),"&Exporter",this);
    actionQuitter = new QAction(QIcon("../Version3/images/quit.png"),"&Quitter",this);

    actionNomSommets = new QAction("&Nom Sommets",this);
    actionValeurSommets = new QAction("&Valeur Sommets",this);
    actionNomArcs = new QAction("&Nom Arcs",this);
    actionValeurArcs = new QAction("&Valeur Arcs",this);
    actionInfosAlgos = new QAction("&Informations Algos",this);

    actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
    actionSauvegarde->setShortcut(QKeySequence("Ctrl+S"));
    actionExporter->setShortcut(QKeySequence("Ctrl+E"));
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
}

void Interface::creerMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    menuFichier->addAction(actionNouveau);//  Ajoute une option "Nouveau"
    menuFichier->addAction(actionOuvrir);//  Ajoute une option "Ouvrir"
    menuFichier->addAction(actionSauvegarde);// Ajoute une option "Sauvegarder"
    menuFichier->addAction(actionExporter);// Ajoute une option "Exporter"
    menuFichier->addSeparator();// Ajoute un séparateur
    menuFichier->addAction(actionQuitter);// Ajoute une Option "Quitter"

    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    menuAffichage->addAction(actionNomSommets);//  Ajoute une option "Nom Sommets"
    menuAffichage->addAction(actionValeurSommets);//  Ajoute une option "Valeur Sommets"
    menuAffichage->addAction(actionNomArcs);//  Ajoute une option "Nom Arcs"
    menuAffichage->addAction(actionValeurArcs);//  Ajoute une option "Valeur Arcs"
    menuAffichage->addAction(actionInfosAlgos);//  Ajoute une option "Valeur Arcs"

   // connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauFichier()));
   // connect(actionNouveau, SIGNAL(triggered()),this, SLOT(creerOnglets()));
    connect(actionInfosAlgos, SIGNAL(triggered()),this, SLOT(fenetre_infos_algos()));

    connect(actionQuitter, SIGNAL(triggered()),qApp, SLOT(quit()));
}

void Interface::creerOutils()//Fonction Initialisation Des Outils
{
      QToolBar* barre_outils;
      QPushButton *plus;//Attribut plus (Zoom)
      QPushButton *moins;//Attribut moins (Dezoom)

      barre_outils = addToolBar("Barre D'outils"); // Creation de la barre de menu
      barre_outils->setMovable(false); // Ne peut etre deplacer
      barre_outils->addAction(QIcon("../Version3/images/new.png"),"Nouveau"); // Ajoute option "Nouveau"
      barre_outils->addAction(QIcon("../Version3/images/open.png"),"Ouvrir"); // Ajoute option "Ouvrir"
      barre_outils->addAction(QIcon("../Version3/images/save.png"),"Sauvegarder"); // Ajoute option "Sauvegarder"
      barre_outils->addAction(QIcon("../Version3/images/export.png"),"Exporter"); // Ajoute option "Exporter"

      plus=new QPushButton(QIcon("../Version3/images/plus.png"),"",barre_outils);//Création Du Bouton +
      plus->setGeometry(600,10,50,25);//Positionnement Et Taille Du Bouton +
      plus->setIconSize(QSize(50,20));//Taille Icone
      plus->show();//Affichage Du Bouton +

      moins=new QPushButton(QIcon("../Version3/images/moins.png"),"",barre_outils);//Création Du Bouton -
      moins->setGeometry(650,10,50,25);//Positionnement Et Taille Du Bouton -
      moins->setIconSize(QSize(50,20));//Taille Icone
      moins->show();//Affichage Du Bouton -

      centrer=new QPushButton(QIcon("../Version3/images/center.png"),"",barre_outils);//Création Du Bouton Centrer
      centrer->setGeometry(700,10,50,25);//Positionnement Et Taille Du Bouton Centrer
      centrer->setIconSize(QSize(50,20));//Taille Icone
      centrer->show();//Affichage Du Bouton Centrer

      bouton_selection_simple=new QPushButton(QIcon("../Version3/images/select_simple.png"),"",barre_outils);//Création Du Bouton Selection Simple
      bouton_selection_simple->setGeometry(750,10,50,25);//Positionnement Et Taille Du Bouton Selection Simple
      bouton_selection_simple->setIconSize(QSize(50,20));//Taille Icone
      bouton_selection_simple->show();//Affichage Du Bouton Selection Simple

      bouton_selection_multiple=new QPushButton(QIcon("../Version3/images/select_mult.png"),"",barre_outils);//Création Du Bouton Selection Multiple
      bouton_selection_multiple->setGeometry(800,10,50,25);//Positionnement Et Taille Du Bouton Selection Multiple
      bouton_selection_multiple->setIconSize(QSize(50,20));//Taille Icone
      bouton_selection_multiple->show();//Affichage Du Bouton Selection Multiple

      bouton_suppression_multiple = new QPushButton(QIcon("../Version3/images/suppr.png"),"",barre_outils);//Création Du Bouton Suppression Multiple
      bouton_suppression_multiple->setGeometry(850,10,50,25);//Positionnement Et Taille Du Bouton Suppression Multiple
      bouton_suppression_multiple->setIconSize(QSize(50,20));//Taille Icone
      bouton_suppression_multiple->show();//Affichage Du Bouton Suppression Multiple

      connect(plus, SIGNAL(released()), this, SLOT(zoom()));//Initialisation Bouton Zoom +
      connect(moins, SIGNAL(released()), this, SLOT(dezoom()));//Initialisation Bouton Zoom -
}

void Interface::fenetre_dessin()//Fonction Fenêtre De Visualisation
{
    scene=new QGraphe(this);//Initialisation D'une Scene Pour La Fenetre De Visualisation
    scene->setSceneRect(0,0,1000,1000);
    vue=new QGraphicsView(scene,this);//Initialisation De La Vue Pour La Fenetre De Visualisation
    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//Barre De Defilement Horizontale
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//Barre De Defilement Verticale
    vue->setSceneRect(scene->sceneRect());
    setCentralWidget(vue);//Fenetre Centrale
}



void Interface::fenetre_sommet()//Fonction Affichage De la Fenêtre Information Sommets
{
    QWidget *info_sommet_widget;//Attribut info_sommet_widget
    QDockWidget *f_sommet;//Attribut f_sommet (Fenêtre Infos Sommets)
    QGridLayout *info_sommet;//Attribut info_sommet

    QLabel *nom_sommet;//Attribut nom_sommet
    QLabel *valeur_sommet;//Attribut valeur_sommet
    QLabel *id_sommet;//Attribut id_sommet
    QLabel *d_plus_sommet;//Attribut d_plus_sommet (Degré Sortant)
    QLabel *d_moins_sommet;//Attribut d_moins_sommet (Degré Entrant)
    QLabel *d_total_sommet;//Attribut d_total

    f_sommet=new QDockWidget(tr("Informations Sommets"),this);//Creation De La Fenêtre en tant que Widget
    f_sommet->setAllowedAreas(Qt::LeftDockWidgetArea);//Positionnement A Gauche De L'ecran
    f_sommet->setMaximumWidth(400);//Taille Max X 400
    f_sommet->setMaximumHeight(220);//Taille Max Y 220
    f_sommet->setMinimumWidth(400);//Taille Max X 400
    f_sommet->setMinimumHeight(220);//Taille Max Y 220
    f_sommet->setVisible(1);//Fenetre Non Visible Par Defaut

    info_sommet_widget=new QWidget();//Creation Widget fenetre Information Sommets

    nom_sommet = new QLabel("Nom:"); // Creation Label Nom
    valeur_sommet = new QLabel("Valeur:");// Creation Label Valeur
    id_sommet = new QLabel("ID:");// Creation Label ID Sommet
    d_plus_sommet = new QLabel("Degré Entrant:");// Creation Label Degré Sortant
    d_moins_sommet = new QLabel("Degré Sortant:");// Creation Label Degré Entrant
    d_total_sommet = new QLabel("Degré Total:");// Creation Label Degré Total

    scene-> nom_sommet_val=new QLineEdit();// Creation Champs Nom
    scene-> valeur_sommet_val = new QLineEdit();// Creation Champs Valeur
    scene-> id_sommet_val = new QLineEdit();// Creation Champs ID Sommet
    scene-> id_sommet_val->setReadOnly(true);
    scene-> d_plus_sommet_val = new QLineEdit();// Creation Champs Degré Sortant
    scene-> d_plus_sommet_val->setReadOnly(true);
    scene-> d_moins_sommet_val = new QLineEdit();// Creation Champs Degré Entrant
    scene-> d_moins_sommet_val->setReadOnly(true);
    scene-> d_total_sommet_val = new QLineEdit();//Creation Champs Degré Total
    scene-> d_total_sommet_val->setReadOnly(true);

    supprimer_sommet = new QPushButton("Supprimer");// Creation Bouton Supprimer

    info_sommet = new QGridLayout;// Creation Grille Organisation
    info_sommet->addWidget(nom_sommet, 0, 0);// Ajout Label Nom
    info_sommet->addWidget(scene->nom_sommet_val, 0, 1);// Ajout Champs Nom
    info_sommet->addWidget(valeur_sommet, 1, 0);// Ajout Label Valeur
    info_sommet->addWidget(scene->valeur_sommet_val, 1, 1);// Ajout Champs Valeur
    info_sommet->addWidget(id_sommet, 2, 0);// Ajout Label ID
    info_sommet->addWidget(scene->id_sommet_val, 2, 1);// Ajout Champs ID
    info_sommet->addWidget(d_plus_sommet, 0, 2);// Ajout Label Degré Sortant
    info_sommet->addWidget(scene->d_plus_sommet_val, 0, 3);// Ajout Champs Degré Sortant
    info_sommet->addWidget(d_moins_sommet, 1, 2);// Ajout Label Degré Entrant
    info_sommet->addWidget(scene->d_moins_sommet_val, 1, 3);// Ajout Champs Degré Entrant
    info_sommet->addWidget(d_total_sommet, 2, 2);// Ajout Label Degré Total
    info_sommet->addWidget(scene->d_total_sommet_val, 2, 3);// Ajout Label Degré Total
    info_sommet->addWidget(supprimer_sommet, 3, 2);// Ajout Supprimer
    info_sommet_widget->setLayout(info_sommet);// Appliquer la grille a la fenêtre

    f_sommet->setWidget(info_sommet_widget);//Appliquer l'eensemble a la fenêtre incrusté
    addDockWidget(Qt::LeftDockWidgetArea, f_sommet);//Ajout De la fenêtre

}

void Interface::fenetre_arc()//Fonction Affichage De la Fenêtre Information Arcs
{
    QWidget *info_arc_widget;//Attribut info_arc_widget
    QDockWidget *f_arc;//Attribut f_arc (Fenêtre Infos Arcs)
    QGridLayout *info_arc;//Attribut info_arc

    QLabel *nom_arc;//Attribut nom_arc
    QLabel *valeur_arc;//Attribut valeur_arc
    QLabel *sommet_origine;//Attribut sommet_origine
    QLabel *sommet_arrive;//Attribut sommet_arrive
    QLabel *id_arc;//Attribut id_arc

    f_arc=new QDockWidget(tr("Informations Arcs"),this);//Creation De La Fenêtre en tant que Widget
    f_arc->setAllowedAreas(Qt::LeftDockWidgetArea);//Positionnement A Gauche De L'ecran
    f_arc->setMaximumWidth(400);//Taille Max X 400
    f_arc->setMaximumHeight(220);//Taille Max Y 220
    f_arc->setMinimumWidth(400);//Taille Max X 400
    f_arc->setMinimumHeight(220);//Taille Max Y 220
    f_arc->setVisible(0);//Fenetre Non Visible Par Defaut

    info_arc_widget=new QWidget();

    nom_arc = new QLabel("Nom:");
    valeur_arc = new QLabel("Valeur:");
    sommet_origine = new QLabel("Sommet Origine:");
    sommet_arrive = new QLabel("Sommet Arrivé:");
    id_arc = new QLabel("ID:");

    scene->nom_arc_val = new QLineEdit();
    scene->valeur_arc_val = new QLineEdit();
    scene->sommet_origine_val = new QLineEdit();
    scene->sommet_origine_val->setReadOnly(true);
    scene->sommet_arrive_val = new QLineEdit();
    scene->sommet_arrive_val->setReadOnly(true);
    scene->id_arc_val = new QLineEdit();
    scene->id_arc_val->setReadOnly(true);

    supprimer_arc = new QPushButton("Supprimer");

    info_arc = new QGridLayout;
    info_arc->addWidget(nom_arc, 0, 0);
    info_arc->addWidget(scene->nom_arc_val, 0, 1);
    info_arc->addWidget(valeur_arc, 1, 0);
    info_arc->addWidget(scene->valeur_arc_val, 1, 1);
    info_arc->addWidget(sommet_origine, 0, 2);
    info_arc->addWidget(scene->sommet_origine_val, 0, 3);
    info_arc->addWidget(sommet_arrive, 1, 2);
    info_arc->addWidget(scene->sommet_arrive_val, 1, 3);
    info_arc->addWidget(id_arc, 2, 0);
    info_arc->addWidget(scene->id_arc_val, 2, 1);
    info_arc->addWidget(supprimer_arc, 3, 2);
    info_arc_widget->setLayout(info_arc);

    f_arc->setWidget(info_arc_widget);
    addDockWidget(Qt::LeftDockWidgetArea, f_arc);
}

void Interface::fenetre_graphe()//Fonction Affichage De la Fenêtre Information Graphe
{
    QWidget *info_graphe_widget;//Attribut info_graphe_widget
    QDockWidget *f_graphe;//Attribut f_graphe (Fenêtre Infos Graphes)
    QGridLayout *info_graphe;//Attribut info_graphe

    QLabel *nombre_sommets;//Attribut nombre_sommets
    QLabel *nombre_arcs;//Attribut nombre_arcs
    QLabel *nom_graphe;//Attribut nom_graphe
    QLabel *type_graphe;//Attribut id_graphe

    f_graphe=new QDockWidget(tr("Informations Graphes"),this);//Creation De La Fenêtre en tant que Widget
    f_graphe->setAllowedAreas(Qt::LeftDockWidgetArea);//Positionnement A Gauche De L'ecran
    f_graphe->setMaximumWidth(400);//Taille Max X 400
    f_graphe->setMaximumHeight(220);//Taille Max Y 220
    f_graphe->setMinimumWidth(400);//Taille Max X 400
    f_graphe->setMinimumHeight(220);//Taille Max Y 220
    f_graphe->setVisible(0);//Fenetre Non Visible Par Defaut

    info_graphe_widget=new QWidget();

    nombre_sommets = new QLabel("Nombre Sommets:");
    nombre_arcs = new QLabel("Nombre Arcs:");
    nom_graphe = new QLabel("Nom:");
    type_graphe = new QLabel("Type:");

    extraire_sgp = new QPushButton("Extraire Sous Graphe Partiel");
    supprimer_tout = new QPushButton("Supprimer Tout");
    mat_info = new QPushButton("Matrice");
    definir_sgp = new QPushButton("Definir Sous Graphe Partiel");

    scene->nombre_sommets_val = new QLineEdit();
    scene->nombre_sommets_val->setReadOnly(true);
    scene->nombre_arcs_val = new QLineEdit();
    scene->nombre_arcs_val->setReadOnly(true);
    scene->nom_graphe_val = new QLineEdit();
    scene->type_graphe_val = new QLineEdit();

    info_graphe = new QGridLayout;
    info_graphe->addWidget(nom_graphe, 0, 0);
    info_graphe->addWidget(scene->nom_graphe_val, 0, 1);
    info_graphe->addWidget(type_graphe, 1, 0);
    info_graphe->addWidget(scene->type_graphe_val, 1, 1);
    info_graphe->addWidget(nombre_sommets, 0, 2);
    info_graphe->addWidget(scene->nombre_sommets_val, 0, 3);
    info_graphe->addWidget(nombre_arcs, 1, 2);
    info_graphe->addWidget(scene->nombre_arcs_val, 1, 3);
    info_graphe->addWidget(mat_info, 2, 0);
    info_graphe->addWidget(definir_sgp,2,1);
    info_graphe->addWidget(supprimer_tout, 2, 2);
    info_graphe->addWidget(extraire_sgp, 3, 1);
    info_graphe_widget->setLayout(info_graphe);

    f_graphe->setWidget(info_graphe_widget);
    addDockWidget(Qt::LeftDockWidgetArea, f_graphe);
}

void Interface::fenetre_infos_algos()
{
    QTextEdit *infos_algos;

    infos_algos = new QTextEdit();
    infos_algos->setWindowTitle("Informations Sur Les Algorithmes");
    infos_algos->setGeometry(450,200,600,400);
    infos_algos->setText("Voici les Différentes Instructions à suivre pour les différents Algorithmes:\n\n"
                         "Dijkstra:\n\n"
                         "Ford-BellMan:\n\n"
                         "Ford Fulkerson;\n\n"
                         "PERT:\n\n"
                         "Graphe Eulerien:\n\n"
                         "Graphe Hamiltonien:\n\n"
                         "Graphe Connexe:\n\n"
                         "Graphe Fortement Connexe:\n\n");
    infos_algos->setReadOnly(true);
    infos_algos->show();
}

void Interface::fenetre_ajout_algo()//Fonction Affichage De la Fenêtre Ajout/Algo
{
     QWidget *bouton_algo_ajout_widget;//Attribut bouton_algo_ajout_widget
     QDockWidget *f_algo;//Attribut f_graphe (Fenêtre Algo)
     QGridLayout *bouton_algo_ajout;//Attribut bouton_algo_ajout

    f_algo=new QDockWidget(tr("Outils"),this);//Creation De La Fenêtre en tant que Widget
    f_algo->setAllowedAreas(Qt::LeftDockWidgetArea);//Positionnement A Gauche De L'ecran
    f_algo->setMaximumWidth(400);//Taille Max X 400
    f_algo->setMaximumHeight(300);//Taille Max Y 220
    f_algo->setMinimumWidth(400);//Taille Max X 400
    f_algo->setMinimumHeight(220);//Taille Max Y 220
    f_algo->setVisible(1);//FenetreVisible Par Defaut
    f_algo->setFeatures(QDockWidget::NoDockWidgetFeatures);//Fenetre Non Modifiable Par L'utilisateur

    bouton_algo_ajout_widget = new QWidget();

    add_sommets=new QPushButton("Ajout Sommets");//Création Du Bouton Ajout Sommets
    add_arcs=new QPushButton("Ajout Arcs");//Création Du Bouton Ajout Arcs
    procedures = new QLabel("Algorithmes:");//Zone De Texte Algorithmes
    liste_procedures = new QComboBox(bouton_algo_ajout_widget);//Menu Déroulant avec la Liste Des Algos

    liste_procedures->addItem("None");//Element 1 par Defaut
    liste_procedures->addItem("Djikstra");//Element 2
    liste_procedures->addItem("Ford Fulkerson");//Element 3
    liste_procedures->addItem("Ford-Bellman");//Element 4
    liste_procedures->addItem("PERT");//Element 5
    liste_procedures->addItem("Graphe Eulerien");//Element 6
    liste_procedures->addItem("Graphe Hamiltonien");//Element 7
    liste_procedures->addItem("Graphe Connexe");//Element 8
    liste_procedures->addItem("Graphe Fortement Connexe");//Element 9

    bouton_algo_ajout = new QGridLayout;
    bouton_algo_ajout->setContentsMargins(0,150,100,0);
    bouton_algo_ajout->addWidget(add_sommets,0,1,1,1,Qt::AlignLeft);
    bouton_algo_ajout->addWidget(add_arcs,1,1,1,1,Qt::AlignLeft);
    bouton_algo_ajout->addWidget(procedures, 2, 0,1,1,Qt::AlignRight);
    bouton_algo_ajout->addWidget(liste_procedures, 2, 1);
    bouton_algo_ajout_widget->setLayout(bouton_algo_ajout);

    f_algo->setWidget(bouton_algo_ajout_widget);
    addDockWidget(Qt::LeftDockWidgetArea, f_algo);
}

void Interface::choix_new()
{
//    scene=new Visualisation(this);//Initialisation D'une Scene Pour La Fenetre De Visualisation
//    vue=new QGraphicsView(scene,this);//Initialisation De La Vue Pour La Fenetre De Visualisation

//    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//Barre De Defilement Horizontale
//    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//Barre De Defilement Verticale

//    QMdiSubWindow *subWindow = new QMdiSubWindow;
//    subWindow->setWidget(vue);
//    subWindow->setGeometry(600,200,600,400);
//    mdi->addSubWindow(subWindow)->show();
}

void Interface::choix_open()
{

}

void Interface::choix_save()
{

}

void Interface::choix_export()
{

}

void Interface::affiche_noms_sommets()
{

}

void Interface::affiche_valeurs_sommets()
{

}

void Interface::affiche_noms_arcs()
{

}

void Interface::affiche_valeurs_arcs()
{

}

void Interface::zoom()//Fonction De Zoom +
{
    zoomIN=1.5;//Valeur Du Zoom

    if(zoomMAX<4)//Condition Pour Ne Pas Zoomer Plus De 4fois
    {
        vue->scale(zoomIN,zoomIN);//Echelle Du Zoom
        zoomMAX++;//Incrémentation
    }


}

void Interface::dezoom()//Fonction De Zoom -
{
    zoomOUT=1.0/zoomIN;//Valeur Du Dezoom

    if(zoomMAX>-4)//Condition Pour Ne Pas Dézoomer Plus De 4fois
    {
        vue->scale(zoomOUT,zoomOUT);//Echelle Du Dezoom
        zoomMAX--;//Décrementation
    }
}

void Interface::nomSommetChanged(int)
{
}

Interface::~Interface()
{

}
