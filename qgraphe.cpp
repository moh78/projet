#include "qgraphe.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include "qmath.h"
#include <QGraphicsItem>
#include "qarc.h"

QLineEdit *QGraphe::getNom_sommet_val() const
{
    return nom_sommet_val;
}

void QGraphe::setQ(QLineEdit *line, QString value)
{
    line->setText(value);
}

//void Visualisation::setNom_sommet_val(int a)
//{
//    nom_sommet_val->setText(QString::number(a));
//}


void QGraphe::supprimerQSommet()
{
     if(this->selectedItems().size()==0) return ;

//    foreach (QGraphicsItem *item, this->selectedItems()) {
//        supprimerqsommet(TrouverQSommet(item));
//         if (item->type() ==QSommet::Type) qgraphicsitem_cast<QSommet *>(item)->supprimerQArcs();
//         this->removeItem(item);
//         delete item;
//     }

//    foreach (QGraphicsItem *item, this->selectedItems()) {
//        if (item->type() == QArc::Type) {
//            this->removeItem(item);
//           // QArc *arrow = qgraphicsitem_cast<QArc *>(item);
//            delete item;
//                                        }
//                                                         }
}

void QGraphe::setNomSommet(QString s)
{
//nom_sommet_val->setText(s);
//graph->_LSommets
  //  if(idActuel==-1) return ;
graph->getLSommets()[idActuel] ->setNom(s.toStdString());
qDebug() << Q_FUNC_INFO << "J'initliasie nom sommet avec case text"<<idActuel;


}

void QGraphe::arc_ajouter()
{
    mode=mode_m::dessin_arc;

}

void QGraphe::deplacer()
{
 mode=mode_m::deplacement;
}

void QGraphe::sommet_ajouter()
{
    mode=mode_m::dessin_sommet;
}

void QGraphe::supprimer()
{
    mode=mode_m::supression;
}

void QGraphe::deleteItem()
{
        foreach (QGraphicsItem *item, this->selectedItems()) {
                this->removeItem(item);
                delete item;
        }

}

//void Visualisation::timerEvent(QTimerEvent *event)
//{
//    Q_UNUSED(event);

//    QList<QSommet *> qsommet;
//    foreach (QGraphicsItem *item, this->items()) {
//        if (QSommet *som = qgraphicsitem_cast<QSommet *>(item))
//            qsommet << som;
//    }

//    foreach (QSommet *som, qsommet)
//        som->calculateForces();

//    bool itemsMoved = false;
//    foreach (QSommet *som, qsommet) {
//        if (som->advance())
//            itemsMoved = true;
//    }

//    if (!itemsMoved) {
//        killTimer(timerId);
//        timerId = 0;
//    }

//}



QGraphe::QGraphe(QObject *parent):QGraphicsScene(parent)//Constructeur
{
    this->nom_sommet_val=new QLineEdit();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    line=0;
    graph=new Graphe(0,"ibra");
}


void QGraphe::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
   {
    if (line != 0 && mode == mode_m::dessin_arc) {

        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();
        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
                 startItems.first() != endItems.first() &&
                startItems.first()->type()==QSommet::Type &&
                 endItems.first()->type()==QSommet::Type ) {
            QSommet *startItem = qgraphicsitem_cast<QSommet *>(startItems.first());
            QSommet *endItem = qgraphicsitem_cast<QSommet *>(endItems.first());
            AjouterQArc(startItem,endItem);
        }

        line=0;

    }

    else if(mouseEvent->button()==Qt::LeftButton && mode==mode_m::dessin_sommet){
        if(this->items(mouseEvent->scenePos()).size()==0){
            AjouterQSommet(mouseEvent->scenePos());
        }
     }

       update();
       QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }


void QGraphe::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)//Fonction Double clique Souris
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();//Action dans la Zone De la Scene
     update();
     QGraphicsScene::mouseDoubleClickEvent(mouseEvent);//Action De Double-Clique
}


void QGraphe::mousePressEvent(QGraphicsSceneMouseEvent * me)//Fonction Clique Souris
{
    if(me->button()==Qt::LeftButton && mode==mode_m::deplacement){
        if(items(me->scenePos()).size()==0) return;
        QGraphicsItem *item=items(me->scenePos()).first();
      if(item->type()==QSommet::Type)
      {
 QSommet *p=  qgraphicsitem_cast<QSommet *>(item) ;
 idActuel=p->getPsommet()->getIds();
 this->setQ(id_sommet_val,QString::number(p->getPsommet()->getIds()));
 this->setQ(nom_sommet_val,QString::fromStdString(graph->getSommet(p->getPsommet()->getIds()).getNom()));
 this->setQ(valeur_sommet_val,QString::number(graph->getSommet(p->getPsommet()->getIds()).getVal1()));
       }

     else if(item->type()==QArc::Type){

      }
        qDebug() << Q_FUNC_INFO << "sommet deplacable  ";
      }

//   else if(me->button()==Qt::LeftButton && mode==mode::dessin_sommet){
//        AjouterQSommet(me->scenePos());
//    }

    else if (me->button()==Qt::LeftButton && mode==mode_m::dessin_arc){
        line = new QGraphicsLineItem(QLineF(me->scenePos(),
                                    me->scenePos()));
        line->setPen(QPen(Qt::red, 2));
        addItem(line);
}
  else  if(mode==mode_m::supression && me->button()==Qt::LeftButton ) {
//   supprimerQSommet();
   if(items(me->scenePos()).size())
    supprimerQObjet(this->items(me->scenePos()).first());
 //  qDebug() << Q_FUNC_INFO << "liste qsommet contient  "<< sommet.size();
    }



    update();
    QGraphicsScene::mousePressEvent(me);//Action De Clique
}


void QGraphe::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mode == mode_m::dessin_arc && line != 0) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }


    else if (mode == mode_m::deplacement){
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }

}


//void Visualisation::itemMoved()
//{
//    if (!timerId)
//        timerId = startTimer(1000 / 25);
//}

void QGraphe::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, Qt::black);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}

void QGraphe::AjouterQSommet(QPointF p)
{
QSommet* s=new QSommet(p) ;
this->addItem(s);
Sommet *so=new Sommet();
s->setPsommet(so);
qDebug() << Q_FUNC_INFO << "on creée le sommet id  =" << s->getPsommet()->getIds();
so->setVal1(Sommet::nbSommet()*100);
graph->ajouterSommet(so);
qDebug() << Q_FUNC_INFO << "matrice =" << Sommet::nbSommet();
}


void QGraphe::supprimerQObjet(QGraphicsItem *item)
{   if(item==NULL) return ;

    if(item->type()==QSommet::Type)  {//supprimer Qsommet et son item
       qgraphicsitem_cast<QSommet *>(item)->supprimerQArcs();
        this->removeItem(item);
        delete item;
    }

    else if(item->type()==QArc::Type) {//supprimer item arc
        this->removeItem(item);
         }
}

void QGraphe::AjouterQArc(QSommet *a, QSommet *b)
{
    QArc *p=new QArc(a,b);
    p->setZValue(-1000);
    this->addItem(p);
graph->ajouterArc(a->getPsommet()->getIds(),b->getPsommet()->getIds());
qDebug() << Q_FUNC_INFO << "Arc ajouter=" << graph->existeArc(a->getPsommet()->getIds(),b->getPsommet()->getIds());

}
