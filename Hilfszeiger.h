/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef HILFSZEIGER_H
#define HILFSZEIGER_H

#include <QObject>
#include <QGraphicsItem>

class Basisstapel;

class Hilfszeiger : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Hilfszeiger(Basisstapel *parent);
    virtual ~Hilfszeiger();

    virtual QRectF boundingRect() const;
    void passe_groesse_an(const QRectF&);

private:
    Basisstapel *meinstapel;
    double breite, hoehe, dicke;

    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif
