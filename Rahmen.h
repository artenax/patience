/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef RAHMEN_H
#define RAHMEN_H

#include <QObject>
#include <QGraphicsItem>

class Basisstapel;

class Rahmen : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Rahmen(Basisstapel* parent);
    virtual ~Rahmen();

    void zeige(Basisstapel*, const QPointF&);
    Basisstapel *aktueller_stapel() const;
    void passe_groesse_an(const QRectF&);

public slots:
    void verstecke();

private:
    QSizeF Groesse;
    Basisstapel* meinstapel;
    double dicke;
    double eckradius;

    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    QRectF boundingRect() const;
};

#endif
