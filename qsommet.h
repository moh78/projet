#ifndef QSOMMET_H
#define QSOMMET_H
#include "qgraphe.h"
#include "qarc.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QList>
#include <QPoint>

class QSommet : public QGraphicsItem
{
public:
    QSommet();
    QSommet(QPointF p);

    void ajouterQArc(QArc *edge);
    QVector<QArc *> arc() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    void calculateForces();
    bool advance();
    void supprimerQArcs();
    void supprimerQArc(QArc *arrow);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getId() const;
    void setId(int value);

    Sommet *getPsommet() const;
    void setPsommet(Sommet *value);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPointF newPos;
    QVector<QArc *> QArcList;
    int id;
    Sommet *psommet;

};

#endif // QSOMMET_H
