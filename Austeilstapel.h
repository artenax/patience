/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef AUSTEILSTAPEL_H
#define AUSTEILSTAPEL_H

#include "Basisstapel.h"

class Austeilstapel : public Basisstapel
{
    Q_OBJECT

public:
    Austeilstapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent = 0);
    virtual ~Austeilstapel();

    virtual void registriere_costapel(Basisstapel*);
    virtual void karte_wurde_aufgedeckt(Karte*);
    virtual bool ablage_moeglich(Karte*) const;
    virtual void undo_karten_ablage(Karte*);

public slots:
    virtual void hilfsanfrage_start(Karte*);

private:
    Basisstapel *costapel;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif
