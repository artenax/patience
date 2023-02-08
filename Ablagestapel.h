/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef ABLAGESTAPEL_H
#define ABLAGESTAPEL_H

#include "Basisstapel.h"

class Ablagestapel : public Basisstapel
{
    Q_OBJECT

public:
    Ablagestapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent = 0);
    virtual ~Ablagestapel();

    virtual bool ablage_moeglich(Karte*) const;

public slots:
    virtual void passe_groesse_an(double);

protected:
    virtual QPointF ablageposition() const;
};

#endif
