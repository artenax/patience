/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef ZIELSTAPEL_H
#define ZIELSTAPEL_H

#include "Basisstapel.h"
#include <QList>

class Siegkontrolle;

class Zielstapel : public Basisstapel
{
    Q_OBJECT

public:
    Zielstapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent = 0);
    virtual ~Zielstapel();

    virtual void registriere_siegkontrolle(Siegkontrolle*);
    virtual void registriere_nachbar_zielstapel(Basisstapel*, Basisstapel*, Basisstapel*);

    virtual void ablage_erfolgt();
    virtual bool ablage_moeglich(Karte *) const;
    virtual bool lege_karte_ab(Karte*);

public slots:
    virtual void hilfsanfrage_start(Karte*);

private:
    Siegkontrolle *siegkontrolle;
    QList<Basisstapel*> nachbarn;
};

#endif
