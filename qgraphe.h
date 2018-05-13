#ifndef QGRAPH_H
#define QGRAPH_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include "sommet.h"
#include "qsommet.h"
#include "qgraphe.h"
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLineEdit>
#include "qarc.h"
#include <QKeyEvent>
#include <QTime>
#include <QGraphicsLineItem>
#include "graphe.h"


enum mode_m {aucun,dessin_arc,dessin_sommet,supression,deplacement};

class QGraphe : public QGraphicsScene//Classe Visualisation
{
    Q_OBJECT

private:
    Graphe *graph;

    int timerId;
    int idActuel;
    int mode=mode_m::aucun;
    QGraphicsLineItem *line;


public slots:
void arc_ajouter();
void deplacer();
void sommet_ajouter();
void supprimer();
void deleteItem();
//void timerEvent(QTimerEvent *event) override;
void supprimerQSommet();
void setNomSommet(QString s);

//void on_itemMoved( QPointF p);
public:
//void itemMoved();
QLineEdit *nom_sommet_val;//Attribut nom_sommet_val
QLineEdit *valeur_sommet_val;//Attribut valeur_sommet_val
QLineEdit *pred_sommet_val;//Attribut pred_sommet_val
QLineEdit *succ_sommet_val;//Attribut succ_sommet_val
QLineEdit *id_sommet_val;//Attribut id_sommet_val
QLineEdit *d_plus_sommet_val;//Attribut d_plus_sommet_val (Degré Sortant)
QLineEdit *d_moins_sommet_val;//Attribut d_moins_sommet_val (Degré Entrant)
QLineEdit *d_total_sommet_val;//Attribut d_total_sommet_val

QLineEdit *nom_arc_val;//Attribut nom_arc_val
QLineEdit *valeur_arc_val;//Attribut valeur_arc_val
QLineEdit *sommet_origine_val;//Attribut sommet_origine_val
QLineEdit *sommet_arrive_val;//Attribut sommet_arrive_val
QLineEdit *id_arc_val;//Attribut id_arc_val

QLineEdit *nombre_sommets_val;//Attribut nombre_sommets_val
QLineEdit *nombre_arcs_val;//Attribut nombre_arcs_val
QLineEdit *nom_graphe_val;//Attribut id_graphe_val
QLineEdit *type_graphe_val;//Attribut type_graphe_val

explicit QGraphe(QObject *parent = 0);//Constructeur
virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);//Fonction Double clique Souris
virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);//Fonction Deplacer Souris
virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);//Fonction Relacher Clique Souris
virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);//Fonction Clique Souris
void drawBackground(QPainter *painter, const QRectF &rect) override;
void AjouterQSommet(QPointF p);
void AjouterQArc(QSommet *a , QSommet *b);
void supprimerQObjet(QGraphicsItem *item);

QLineEdit *getNom_sommet_val() const;
void setQ(QLineEdit * line, QString value);
};

#endif // VISUALISATION_H
