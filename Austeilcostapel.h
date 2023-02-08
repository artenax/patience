/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef AUSTEILCOSTAPEL_H
#define AUSTEILCOSTAPEL_H

#include "Basisstapel.h"

class Austeilcostapel : public Basisstapel
{
    Q_OBJECT

public:
    Austeilcostapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent = 0);
    virtual ~Austeilcostapel();

    virtual void registriere_austeilstapel(Basisstapel*);
    virtual bool ablage_moeglich(Karte *) const;
    virtual bool lege_karte_ab(Karte*);
    virtual void entferne_karte(Karte*);
    virtual const QStringList speichere() const;
    virtual bool lade(const QStringList&);
    virtual void initialisiere_karte(Karte*);
    virtual void undo_karten_ablage(Karte*);
    virtual void karten_auffaechern();
    virtual void karte_wurde_aufgedeckt(Karte*);

public slots:
    virtual void hilfsanfrage_start(Karte*);
    virtual void passe_groesse_an(double);
    virtual void alle_karten_einreihen();

private:
    Basisstapel *austeilstapel;
};

#endif
